#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long cl[4];
long long classify(long long len) {
  if (len < b) return 0;
  if (len < a) return 1;
  if (len < b + b) return 2;
  return 3;
}
signed main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    cin >> a >> b;
    long long len3 = -1;
    string s;
    cin >> s;
    for (long long i = 0; i < s.size();) {
      if (s[i] == 'X') {
        while (i < s.size() && s[i] == 'X') i++;
        continue;
      }
      long long j = i;
      while (j < s.size() && s[j] == '.') {
        j++;
      }
      cl[classify(j - i)]++;
      if (classify(j - i) == 3) len3 = j - i;
      i = j;
    }
    if (cl[1]) {
      cout << "NO\n";
    } else if (cl[3] >= 2) {
      cout << "NO\n";
    } else if (cl[3] == 1) {
      long long r = len3 - a;
      long long l = 0;
      bool fl = false;
      while (l <= r) {
        long long x = classify(l);
        long long y = classify(r);
        if (x == 1 || x == 3 || y == 1 || y == 3) {
          l++, r--;
          continue;
        }
        if (x == 2 && y == 2) {
          if (cl[2] % 2 == 0) {
            cout << "YES\n";
            fl = true;
            break;
          }
        } else if (x == 2 || y == 2) {
          if ((cl[2] + 1) % 2 == 0) {
            cout << "YES\n";
            fl = true;
            break;
          }
        } else {
          if (cl[2] % 2 == 0) {
            cout << "YES\n";
            fl = true;
            break;
          }
        }
        l++;
        r--;
      }
      if (!fl) cout << "NO\n";
    } else {
      if (cl[2] % 2 == 0) {
        cout << "NO\n";
      } else
        cout << "YES\n";
    }
    for (long long i = 0; i < 4; i++) cl[i] = 0;
  }
}
