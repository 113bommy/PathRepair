#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> ans;
inline void solve() {
  for (int i = 0; i < k; ++i) ans.push_back(1);
  if (k == 1) {
    for (int i = 0; i < m; i += n - 1) ans.push_back(n + i);
  } else {
    int last = n;
    for (int i = 0; i < m; i += n) {
      ans.push_back(last);
      for (int j = 0; j < k - 1; ++j) ans.push_back(last + 1);
      last += n;
    }
    if (last == n + m) ans.push_back(n + m);
  }
}
inline void read() { cin >> n >> m >> k; }
inline void print() {
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i)
    printf("%d%c", ans[i], (i + 1 == ans.size()) ? '\n' : ' ');
}
int main() {
  read();
  solve();
  print();
  return 0;
}
