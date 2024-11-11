#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const int N = 2e6 + 10;
int a[N], b[N];
vector<long long> st;
void precalc() {
  st.push_back(0);
  for (long long i = 1; i <= 63; i++) {
    st.push_back((1 << i) - 1);
  }
}
long long solve_small(long long l, long long r) {
  long long x = 0;
  long long ans = 0;
  for (long long p = l; p <= r; p++) {
    if (ans < __builtin_popcount(p)) {
      ans = __builtin_popcount(p);
      x = p;
    }
  }
  return x;
}
long long rec(long long l, long long r) {
  int ans = 0;
  long long p = l;
  long long last = 0;
  for (int i = 0; i <= 100 && p <= r; i++) {
    p += ~p & -~p;
    if (p <= r) last = p;
  }
  return last;
}
int main() {
  int n;
  cin >> n;
  precalc();
  while (n--) {
    long long l, r;
    cin >> l >> r;
    cout << rec(l, r) << "\n";
  }
}
