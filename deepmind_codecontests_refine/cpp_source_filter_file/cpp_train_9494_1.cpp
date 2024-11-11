#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
void add(long long int &a, long long int b) {
  a += b;
  if (a >= 1000000007) a %= 1000000007;
}
void subtract(long long int &a, long long int b) {
  a -= (b - 1000000007);
  if (a >= 1000000007) a -= 1000000007;
}
long long int multiply(long long int a, long long int b) {
  long long int res = a;
  res *= b;
  if (res >= 1000000007) res %= 1000000007;
  return res;
}
long long int n, a[100005];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    long long int a, b, c;
    cin >> n;
    cin >> a >> b >> c;
    string s;
    cin >> s;
    long long int a1 = 0, a2 = 0, a3 = 0;
    long long int req = (n + 1) / 2;
    for (long long int i = 0; i < s.size(); i++) {
      if (s[i] == 'R') a1++;
      if (s[i] == 'P') a2++;
      if (s[i] == 'S') a3++;
    }
    long long int h1 = 0, h2 = 0, h3 = 0;
    long long int count = 0;
    long long int e1 = 0, e2 = 0, e3 = 0;
    count = min({a1, b});
    if (a1 < b) e1 = b - a1;
    count += min({a2, c});
    if (a2 < c) e2 = c - a2;
    count += min({a3, a});
    if (a3 < a) e3 = a - a3;
    if (count < req) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
      for (long long int i = 0; i < s.size(); i++) {
        if (s[i] == 'R') {
          if (b > 0) {
            cout << "P";
            b--;
          } else {
            if (e1 > 0) {
              cout << "R";
              e1--;
            } else if (e3 > 0) {
              cout << "S";
              e3--;
            }
          }
        } else if (s[i] == 'P') {
          if (c > 0) {
            cout << "S";
            c--;
          } else {
            if (e1 > 0) {
              cout << "R";
              e1--;
            } else if (e2 > 0) {
              cout << "P";
              e2--;
            }
          }
        } else {
          if (a > 0) {
            cout << "R";
            a--;
          } else {
            if (e2 > 0) {
              cout << "P";
              e2--;
            } else if (e3 > 0) {
              cout << "S";
              e3--;
            }
          }
        }
      }
    }
    cout << "\n";
  }
}
