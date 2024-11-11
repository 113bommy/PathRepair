#include <bits/stdc++.h>
using namespace std;
int c[201];
vector<int> pre[201];
int n;
int solve(int current) {
  bool mark[201] = {0};
  int cnt = 0, ans = 0;
  while (cnt < n) {
    for (int i = 0; i < n; i++) {
      if (mark[i]) continue;
      if (c[i] != current + 1) continue;
      bool all_pre_ok = true;
      for (int j = 0; j < pre[i].size() && all_pre_ok; j++)
        if (!mark[pre[i][j]]) all_pre_ok = false;
      if (!all_pre_ok) continue;
      cnt++;
      mark[i] = 1;
      i = 0;
    }
    current++;
    current %= 3;
    ans++;
  }
  return ans - 1;
}
int main() {
  int a, b;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) {
    cin >> a;
    for (int j = 0; j < a; j++) {
      cin >> b;
      pre[i].push_back(b - 1);
    }
  }
  cout << n + min(solve(0), min(solve(1), solve(2))) << endl;
  return 0;
}
