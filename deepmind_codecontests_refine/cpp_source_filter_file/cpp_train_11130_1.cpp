#include <bits/stdc++.h>
int n, m;
bool done[10];
int map[256];
std::vector<char> check;
std::vector<std::string> list;
bool top[256];
int left;
int right;
int atom[256];
int btom[256];
int decode(const std::string& str) {
  int time = 1;
  int sum = 0;
  for (int i = str.length() - 1; 0 <= i; --i) {
    sum += map[str[i]] * time;
    time *= 10;
  }
  return sum;
}
bool ok() {
  int sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    sum += decode(list[i]);
  }
  return sum == decode(list[n - 1]);
}
int dfs(int depth) {
  if (depth == check.size()) {
    return left == right;
  }
  int cnt = 0;
  for (int i = 0; i < 10; ++i) {
    if (done[i]) {
      continue;
    }
    if (i == 0 && top[check[depth]]) {
      continue;
    }
    done[i] = true;
    map[check[depth]] = i;
    left += atom[check[depth]] * i;
    right += btom[check[depth]] * i;
    cnt += dfs(depth + 1);
    left -= atom[check[depth]] * i;
    right -= btom[check[depth]] * i;
    done[i] = false;
  }
  return cnt;
}
int main() {
  for (;;) {
    std::cin >> n;
    if (n == 0) {
      break;
    }
    list.clear();
    memset(atom, 0, sizeof(atom));
    memset(btom, 0, sizeof(btom));
    memset(top, 0, sizeof(top));
    std::set<char> set;
    for (int i = 0; i < n; ++i) {
      std::string str;
      std::cin >> str;
      list.push_back(str);
      for (char c : str) {
        set.insert(c);
      }
      int time = 1;
      for (int j = str.length() - 1; 0 <= j; --j) {
        if (i < n - 1) {
          atom[str[j]] += time;
        } else {
          btom[str[j]] += time;
        }
        time *= 10;
      }
      if (str.length() > 1) {
        top[str[0]] = true;
      }
    }
    check.clear();
    for (char c : set) {
      check.push_back(c);
    }
    memset(done, 0, sizeof(done));
    int ans = dfs(0);
    std::cout << ans << std::endl;
  }
}
