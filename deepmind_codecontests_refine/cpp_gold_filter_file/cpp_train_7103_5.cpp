#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
const long long inf = 1e18 + 100;
const long long mod = 1e9 + 7;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long arr[k][26];
  memset(arr, 0, sizeof arr);
  string s;
  cin >> s;
  for (int i = 0, j = 0; i < s.size(); i++) {
    arr[j % (k)][s[i] - 'a']++;
    j++;
  }
  long long ans = 0;
  for (int i = 0; i < (k + 1) / 2; i++) {
    long long mx_c = 0, tot = 0;
    int temp[26] = {0};
    memset(temp, 0, sizeof temp);
    for (int j = 0; j < 26; j++) {
      if (i == k - i - 1) {
        temp[j] += arr[i][j];
        continue;
      }
      temp[j] += arr[i][j] + arr[k - i - 1][j];
    }
    for (int j = 0; j < 26; j++) {
      mx_c = max(mx_c, (long long)temp[j]);
      tot += temp[j];
    }
    ans += tot - mx_c;
  }
  cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
