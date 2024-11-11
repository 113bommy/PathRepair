#include <bits/stdc++.h>
const int cmaxn = 300004;
const int cinf = 1000000007;
struct data {
  std::pair<int, int> first_min;
  std::pair<int, int> second_min;
  int add = 0;
  int emp;
};
data t[8 * cmaxn];
std::vector<int> permutation(cmaxn);
std::vector<int> new_permutation(cmaxn);
std::pair<int, int> FindNeigh(int number, int num) {
  int first = permutation[number - 1];
  int second = permutation[number + 1];
  if (first < permutation[number]) {
    first = num;
  }
  if (second < permutation[number] || number + 1 == num) {
    second = num;
  }
  if (second < first) {
    std::swap(second, first);
  }
  return std::make_pair(first, second);
}
int CountMin(data left, data right, int min_val) {
  int cnt = 0;
  if (left.first_min.first == min_val) {
    cnt += left.first_min.second;
  }
  if (left.second_min.first == min_val) {
    cnt += left.second_min.second;
  }
  if (right.first_min.first == min_val) {
    cnt += right.first_min.second;
  }
  if (right.second_min.first == min_val) {
    cnt += right.second_min.second;
  }
  return cnt;
}
data Combine(data left, data right) {
  data temp;
  if (!left.first_min.second)
    temp = right;
  else if (!right.first_min.second)
    temp = left;
  else {
    if (!left.second_min.second) {
      left.second_min.first = cinf;
    }
    if (!right.second_min.second) {
      right.second_min.first = cinf;
    }
    int min_val = std::min(left.first_min.first, right.first_min.first);
    temp.first_min.first = min_val;
    temp.first_min.second = CountMin(left, right, min_val);
    min_val = (left.first_min.first + right.first_min.first) - min_val;
    if (min_val == temp.first_min.first) {
      min_val = left.second_min.first;
    }
    min_val = std::min(min_val, left.second_min.first);
    min_val = std::min(min_val, right.second_min.first);
    temp.second_min.first = min_val;
    temp.second_min.second = CountMin(left, right, min_val);
  }
  temp.emp = left.emp + right.emp;
  temp.add = 0;
  return temp;
}
void Push(int v) {
  if (t[v].add) {
    t[v * 2].add += t[v].add;
    t[v * 2 + 1].add += t[v].add;
    t[v].first_min.first += t[v].add;
    t[v].second_min.first += t[v].add;
    if (t[v].emp) {
      if (!t[v].first_min.second || t[v].add < t[v].first_min.first) {
        t[v].second_min = t[v].first_min;
        t[v].first_min = std::make_pair(t[v].add, t[v].emp);
        t[v].emp = 0;
      } else if (!t[v].second_min.second || t[v].add < t[v].second_min.first) {
        t[v].second_min = std::make_pair(t[v].add, t[v].emp);
        t[v].emp = 0;
      }
    }
    t[v].add = 0;
  }
}
void Update(int v, int tl, int tr, int l, int r, int add) {
  Push(v);
  if (l > r) return;
  if (tl == l && r == tr) {
    t[v].add += add;
    Push(v);
  } else {
    int tm = tl + (tr - tl) / 2;
    Update(v * 2, tl, tm, l, std::min(tm, r), add);
    Update(v * 2 + 1, tm + 1, tr, std::max(tm + 1, l), r, add);
    t[v] = Combine(t[v * 2], t[v * 2 + 1]);
  }
}
data GetMin(int v, int tl, int tr, int l, int r) {
  Push(v);
  if (l > r) {
    data temp;
    temp.first_min.second = 0;
    return temp;
  }
  if (tl == l && r == tr) return t[v];
  int tm = tl + (tr - tl) / 2;
  data left = GetMin(v * 2, tl, tm, l, std::min(tm, r));
  data right = GetMin(v * 2 + 1, tm + 1, tr, std::max(tm + 1, l), r);
  return Combine(left, right);
}
void Build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v].first_min = t[v].second_min = std::make_pair(0, 0);
    t[v].emp = 1;
  } else {
    int tm = tl + (tr - tl) / 2;
    Build(v * 2, tl, tm);
    Build(v * 2 + 1, tm + 1, tr);
    t[v] = Combine(t[v * 2], t[v * 2 + 1]);
  }
}
int main() {
  int num;
  std::cin >> num;
  for (int i = 0; i < num; i++) {
    std::cin >> permutation[i];
    new_permutation[--permutation[i]] = i;
  }
  Build(1, 0, num - 1);
  long long answer = 0;
  for (int left = num - 1; left >= 0; left--) {
    std::pair<int, int> neighbor = FindNeigh(new_permutation[left], num);
    Update(1, 0, num - 1, left, neighbor.first - 1, 1);
    Update(1, 0, num - 1, neighbor.second, num - 1, -1);
    data temp = GetMin(1, 0, num - 1, 0, num - 1);
    answer += temp.first_min.second + temp.second_min.second;
  }
  answer -= num;
  std::cout << answer;
  return 0;
}
