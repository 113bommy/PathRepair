#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main() {
  int n;
  cin >> n;
  vector<int> even, odd;
  vector<vector<int> > ans(n);
  for (int i = 1; i <= n * n; i += 2) odd.push_back(i);
  for (int i = 2; i <= n * n; i += 2) even.push_back(i);
  for (int i = 1; i <= n / 2; i++) {
    int cntodd = (i - 1) * 2 + 1;
    int cnteven = n - i;
    for (int j = 0; j < cnteven / 2; j++) {
      ans[i - 1].push_back(even.back());
      even.pop_back();
      ans[n - i].push_back(even.back());
      even.pop_back();
    }
    for (int j = 0; j < cntodd; j++) {
      ans[i - 1].push_back(odd.back());
      odd.pop_back();
      ans[n - i].push_back(odd.back());
      odd.pop_back();
    }
    for (int j = 0; j < cnteven / 2; j++) {
      ans[i - 1].push_back(even.back());
      even.pop_back();
      ans[n - i].push_back(even.back());
      even.pop_back();
    }
  }
  for (int j = 0; j < n; j++) {
    ans[n / 2].push_back(odd.back());
    odd.pop_back();
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      printf("%d%c", ans[i - 1][j - 1], j == n ? '\n' : ' ');
  }
  return 0;
}
