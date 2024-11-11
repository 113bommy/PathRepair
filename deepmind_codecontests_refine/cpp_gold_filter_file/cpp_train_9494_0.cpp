#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e4 + 4;
const long long maxn1 = 300 + 4;
long long n, m, k;
long long maxd = -(1e17), mind = 1e17;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a, b, c;
  cin >> n;
  string s;
  long long r[4];
  for (int i = 0; i < n; i++) {
    cin >> m;
    cin >> a >> b >> c;
    cin >> s;
    r[1] = 0;
    r[2] = 0;
    r[3] = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'R') {
        r[1]++;
      } else if (s[i] == 'S') {
        r[2]++;
      } else
        r[3]++;
    }
    if (min(r[1], b) + min(r[2], a) + min(r[3], c) >= (s.size() + 1) / 2) {
      if (r[1] <= b) {
        b -= r[1];
        r[1] = 0;
      } else {
        r[1] -= b;
        b = 0;
      }
      if (r[2] <= a) {
        a -= r[2];
        r[2] = 0;
      } else {
        r[2] -= a;
        a = 0;
      }
      if (r[3] <= c) {
        c -= r[3];
        r[3] = 0;
      } else {
        r[3] -= c;
        c = 0;
      }
      cout << "YES" << endl;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') {
          if (r[1] != 0) {
            if (c != 0) {
              cout << 'S';
              c--;
            } else if (a != 0) {
              cout << 'R';
              a--;
            } else {
              cout << 'P';
            }
            r[1]--;
          } else {
            cout << 'P';
          }
        } else if (s[i] == 'S') {
          if (r[2] != 0) {
            if (c != 0) {
              cout << 'S';
              c--;
            } else if (b != 0) {
              cout << 'P';
              b--;
            } else {
              cout << 'R';
            }
            r[2]--;
          } else {
            cout << 'R';
          }
        } else {
          if (r[3] != 0) {
            if (b != 0) {
              cout << 'P';
              b--;
            } else if (a != 0) {
              cout << 'R';
              a--;
            } else
              cout << 'S';
            r[3]--;
          } else {
            cout << 'S';
          }
        }
      }
      cout << endl;
    } else
      cout << "NO" << endl;
  }
}
