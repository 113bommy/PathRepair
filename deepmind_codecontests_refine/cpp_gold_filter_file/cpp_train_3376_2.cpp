#include <bits/stdc++.h>
int IntMaxVal = (int)1e20;
int IntMinVal = (int)-1e20;
long long LongMaxVal = (long long)1e20;
long long LongMinVal = (int)-1e20;
template <typename T>
struct argument_type;
template <typename T, typename U>
struct argument_type<T(U)> {};
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& s) {
  is >> s.first >> s.second;
  return is;
}
void pr(int n, char c) {
  for (int i = 0; i < n; ++i) cout << c;
}
void print(int a, int b, int ga, int gb) {
  while (ga || gb) {
    if (gb > 0) {
      int n = b / gb;
      pr(n, 'x');
      b -= n;
      gb--;
    }
    if (ga > 0) {
      int n = a - ga + 1;
      pr(n, 'o');
      a -= n;
      ga--;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  auto opt = make_pair(LongMinVal, 0);
  long long a;
  cin >> a;
  ;
  long long b;
  cin >> b;
  ;
  if (a == 0) {
    cout << -(b * b) << endl;
    for (int i = 0; i < b; ++i) cout << 'x';
    return 0;
  }
  for (int g0 = 1; g0 < a + 1; ++g0) {
    long long rem = a - g0 + 1;
    long long x = g0 - 1 + rem * rem;
    long long g1 = g0 + 1;
    long long c0 = b / g1;
    long long count1 = b % g1;
    long long c1 = c0 + 1;
    long long count0 = g1 - count1;
    x -= count0 * c0 * c0;
    x -= count1 * c1 * c1;
    { opt = max(opt, make_pair(x, g0)); };
  }
  cout << opt.first << endl;
  print(a, b, opt.second, opt.second + 1);
}
