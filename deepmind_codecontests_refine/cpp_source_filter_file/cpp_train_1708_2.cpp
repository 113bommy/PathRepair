#include <bits/stdc++.h>
using namespace std;
string s;
int m;
int dp[10000][19][19];
int ans[10000];
int recur(int i, int diff, int last) {
  if (i > 0 && diff <= 0 || diff > 10) return 0;
  if (i == m) {
    cout << "YES\n";
    for (long long int j = 0; j < m; j++) cout << ans[j] << " ";
    cout << "\n";
    return 1;
  }
  for (long long int k = 0; k < 10; k++) {
    if (s[k] == '1' && k + 1 != last) {
      ans[i] = k + 1;
      if (recur(i + 1, k + 1 - diff, k + 1)) return 1;
    }
  }
  return 0;
}
int main() {
  cin >> s;
  cin >> m;
  if (!recur(0, 0, 10)) cout << "NO" << endl;
  return 0;
}
