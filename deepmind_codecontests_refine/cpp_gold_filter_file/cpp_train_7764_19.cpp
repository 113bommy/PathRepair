#include <bits/stdc++.h>
using namespace std;
char BUF[3500000];
inline void I(int& a) { scanf("%d", &a); }
inline void I(int& a, int& b) { scanf("%d%d", &a, &b); }
inline void I(int& a, int& b, int& c) { scanf("%d%d%d", &a, &b, &c); }
inline void I(int& a, int& b, int& c, int& d) {
  scanf("%d%d%d%d", &a, &b, &c, &d);
}
inline void L(long long& a) { scanf("%lld", &a); }
inline void L(long long& a, long long& b) { scanf("%lld%lld", &a, &b); }
inline void L(long long& a, long long& b, long long& c) {
  scanf("%lld%lld%lld", &a, &b, &c);
}
inline void L(long long& a, long long& b, long long& c, long long& d) {
  scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
}
inline void S(string& str) {
  str.clear();
  scanf("%s", BUF);
  int s = strlen(BUF);
  for (int i = 0; i < s; i++) str.push_back(BUF[i]);
}
inline void SV(vector<int>& v) {
  v.clear();
  scanf("%s", BUF);
  int s = strlen(BUF);
  for (int i = 0; i < s; i++)
    if ('a' <= BUF[i] && BUF[i] <= 'z')
      v.push_back(BUF[i] - 'a');
    else
      v.push_back(BUF[i] - 'A');
}
const auto EPS = 1e-10;
const auto INF = 100000000;
const auto MOD = 1000000007;
long long n, q;
int main() {
  L(n, q);
  for (int i = 0; i < q; i++) {
    long long x;
    string s;
    L(x);
    S(s);
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == 'U') {
        for (int k = 0; k < 65; k++) {
          if ((1LL << k) & x) {
            if ((1LL << (k + 1)) & x) {
              x -= (1LL << k);
            } else {
              x += (1LL << k);
            }
            break;
          }
        }
        if (x > n) x /= 2;
      } else if (s[j] == 'R') {
        if (x & 1) continue;
        for (int k = 0; k < 65; k++) {
          if ((1LL << k) & x) {
            x += (1LL << (k - 1));
            break;
          }
        }
      } else {
        if (x & 1) continue;
        for (int k = 0; k < 65; k++) {
          if ((1LL << k) & x) {
            x -= (1LL << (k - 1));
            break;
          }
        }
      }
    }
    cout << x << endl;
  }
}
