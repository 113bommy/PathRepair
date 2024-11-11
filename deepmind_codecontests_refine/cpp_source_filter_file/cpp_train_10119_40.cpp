#include <bits/stdc++.h>
using namespace std;
const int d[9] = {1,      10,       100,       1000,      10000,
                  100000, 10000000, 100000000, 1000000000};
int a[10][10];
int ans;
int num[10];
bool used[10];
int n;
void dfs(int dep, int k) {
  if (dep > k) {
    int number;
    int max = -1, min = 2147483647;
    for (int i = 0; i < n; i++) {
      number = 0;
      for (int j = 1; j <= k; j++) number += a[i][num[j]] * d[k - j];
      if (number > max) max = number;
      if (number < min) min = number;
    }
    if (max - min < ans) ans = max - min;
    return;
  }
  for (int i = 0; i < k; i++)
    if (!used[i]) {
      used[i] = 1;
      num[dep] = i;
      dfs(dep + 1, k);
      used[i] = 0;
    }
}
int main() {
  int k;
  cin >> n >> k;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < k; j++) a[i][j] = s[j] - '0';
  }
  ans = 2147483647;
  dfs(1, k);
  cout << ans << endl;
  return 0;
}
