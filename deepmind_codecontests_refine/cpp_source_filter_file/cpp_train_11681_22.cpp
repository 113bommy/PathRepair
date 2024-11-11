#include <bits/stdc++.h>
inline long long read() {
  long long x = 0, f = 1;
  char c = 'a';
  for (; c > '9' || c < '0'; c = getchar()) {
    if (c == '-') f = -1;
  }
  for (; c >= '0' && c <= '9'; c = getchar()) {
    x = x * 10 + c - '0';
  }
  return x * f;
}
inline double query(int t, int x, int y, int z) {
  std::cout << t << " " << x << " " << y << " " << z << std::endl;
  double ans;
  std::cin >> ans;
  return ans;
}
struct Node {
  int pos;
  double dis;
} now;
std::vector<Node> vec_left, vec_right, vec_left_l, vec_right_l;
int ans[1005];
inline void work() {
  std::ios::sync_with_stdio(false);
  int n, top = 1;
  std::cin >> n;
  ans[1] = 1;
  for (int i = 3; i <= n; i++) {
    int x = query(2, 1, 2, i);
    now.pos = i;
    if (x == 1)
      vec_left.push_back(now);
    else
      vec_right.push_back(now);
  }
  for (auto i = vec_left.begin(); i != vec_left.end(); i++)
    i->dis = query(1, 1, 2, i->pos);
  for (auto i = vec_right.begin(); i != vec_right.end(); i++)
    i->dis = query(1, 1, 2, i->pos);
  std::sort(vec_left.begin(), vec_left.end(),
            [](const Node &a, const Node &b) { return a.dis < b.dis; });
  std::sort(vec_right.begin(), vec_right.end(),
            [](const Node &a, const Node &b) { return a.dis < b.dis; });
  if (vec_right.size()) {
    Node tmp = vec_right.back();
    vec_right.pop_back();
    for (auto i : vec_right) {
      int x = query(2, 1, tmp.pos, i.pos);
      if (x == 1)
        vec_right_l.push_back(i);
      else
        ans[++top] = i.pos;
    }
    ans[++top] = tmp.pos;
    if (vec_right_l.size()) {
      for (auto i = vec_right_l.rbegin(); i != vec_right_l.rend(); i++)
        ans[++top] = i->pos;
    }
  }
  ans[++top] = 2;
  if (vec_left.size()) {
    Node tmp = vec_left.back();
    vec_left.pop_back();
    for (auto i : vec_left) {
      int x = query(2, 1, tmp.pos, i.pos);
      if (x == 1)
        vec_left_l.push_back(i);
      else
        ans[++top] = i.pos;
    }
    ans[++top] = tmp.pos;
    if (vec_left_l.size()) {
      for (auto i = vec_left_l.rbegin(); i != vec_left_l.rbegin(); i++)
        ans[++top] = i->pos;
    }
  }
  for (int i = 0; i <= n; i++) std::cout << ans[i] << " ";
  std::cout << std::endl;
}
int main() {
  work();
  return 0;
}
