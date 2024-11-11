#include <bits/stdc++.h>
const int N = 2e5 + 5;
long long v[N];
struct Op {
  int type, x, y;
};
std::vector<Op> q;
std::vector<int> vec;
int main() {
  int m, n, ind = 1;
  std::cin >> m;
  q.resize(m);
  for (int i = 0; i < m; i++) {
    std::cin >> q[i].type >> q[i].x;
    if (q[i].type == 2) std::cin >> q[i].y;
  }
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> v[i];
  long long len = 0;
  for (Op curr : q) {
    if (ind > n) break;
    if (curr.type == 1) {
      if (vec.size() < 100000) vec.push_back(curr.x);
      len++;
      if (v[ind] == len) ind++, std::cout << curr.x << " ";
    } else {
      for (int i = 0; i < curr.x * curr.y; i++)
        if (vec.size() + i < 100000)
          vec.push_back(vec[i % curr.x]);
        else
          break;
      while (ind <= n and v[ind] <= len + 1LL * curr.x * curr.y)
        std::cout << vec[(v[ind] - len - 1) % curr.x] << " ", ind++;
      len += 1LL * curr.x * curr.y;
    }
  }
}
