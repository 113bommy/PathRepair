#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
void solve() {
  string s;
  cin >> s;
  map<long long int, long long int> m;
  long long int c = 0;
  for (long long int(i) = 0; (i) < (s.size()); (i)++) {
    if (s[i] == ',') {
      if (c != 0) {
        m[c]++;
      }
      c = 0;
    } else {
      c = c * 10 + (long long int)(s[i] - '0');
    }
  }
  if (c != 0) m[c]++;
  c = 0;
  long long int p = 0, r = 0;
  string s1 = "";
  for (long long int(i) = 0; (i) < (1001); (i)++) {
    if (m[i] != 0) {
      if (c == 0) p = i;
      c++;
    } else {
      if (c > 1) {
        if (r == 0) {
          cout << p << "-" << i - 1;
          r++;
        } else {
          cout << "," << p << "-" << i - 1;
        }
      } else if (c != 0) {
        if (r == 0) {
          cout << p;
          r++;
        } else {
          cout << "," << p;
        }
      }
      c = 0;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  for (long long int _ = 0; _ < t; _++) {
    solve();
  }
  return 0;
}
