#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const long long INF = 9223372000000000000;
const int inf = 2147483647;
const long double PI = acos(-1);
const int MAXN = 20005;
void solve() { return; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  vector<string> v;
  for (int i = 0; i < 60; i++) {
    long long temp = pow(2, i);
    v.emplace_back(to_string(temp));
  }
  while (t--) {
    int n;
    cin >> n;
    if (!(n & n - 1)) {
      cout << 0 << "\n";
      continue;
    }
    string s = to_string(n);
    n = s.size();
    int ans = n + 1;
    for (int i = 0; i < 60; i++) {
      int temp = 0;
      int j = 0, k = 0, m = v[i].size();
      while (j < n && k < m) {
        if (s[j] == v[i][k]) {
          j++;
          k++;
          continue;
        }
        j++;
        temp++;
      }
      temp += (n - j);
      temp += (m - k);
      ans = min(ans, temp);
    }
    cout << ans << "\n";
  }
  return 0;
}
