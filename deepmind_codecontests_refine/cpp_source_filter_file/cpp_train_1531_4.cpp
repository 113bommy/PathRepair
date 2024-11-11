#include <bits/stdc++.h>
using namespace std;
const int INF = 0x2aaaaaaa;
const long long INFLL = 0x1f1f1f1f1f1f1f1fLL;
template <class A, class B>
inline ostream& operator<<(ostream& st, const pair<A, B>& P) {
  return st << "(" << P.first << "," << P.second << ")";
};
template <class A, class B>
inline pair<A, B> operator+(const pair<A, B>& P, const pair<A, B>& Q) {
  return pair<A, B>(P.first + Q.first, P.second + Q.second);
};
template <class A, class B>
inline pair<A, B> operator-(const pair<A, B>& P, const pair<A, B>& Q) {
  return pair<A, B>(P.first - Q.first, P.second - Q.second);
};
string s[2003];
int a[2000];
int b[2000];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) a[j] += s[i][j] - '0';
  }
  for (int i = 0; i < n; i++) {
    memcpy(b, a, sizeof(a));
    bool f = true;
    for (int j = 0; j < m; j++) {
      b[i] -= s[i][j] - '0';
      if (b[i] == 0) f = false;
    }
    if (f) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
