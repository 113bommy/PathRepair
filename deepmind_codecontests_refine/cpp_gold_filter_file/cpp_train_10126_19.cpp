#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
long long int csb(long long int x) {
  if (x <= 0) return 0;
  return (x % 2 == 0 ? 0 : 1) + csb(x / 2);
}
long long int tb(long long int n) {
  long long int count = 0;
  while (n) {
    count++;
    n >>= 1;
  }
  return count;
}
bool ip2(long long int n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, c = 0, f = -1, m = -1 * (int)1e9, e = 1, o = (int)1e9,
                     p = 0, x = 0, y = 0, ans = 1, q, x2, y1, y3, y2;
    cin >> n;
    string s[n];
    map<char, long long int> v;
    for (long long int i = 0; i < n; i++) cin >> s[i];
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < s[i].size(); j++) {
        v[s[i][j]]++;
      }
    }
    for (auto it = v.begin(); it != v.end(); it++) {
      if (it->second % n != 0) f = 1;
    }
    if (f == 1)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
  return 0;
}
