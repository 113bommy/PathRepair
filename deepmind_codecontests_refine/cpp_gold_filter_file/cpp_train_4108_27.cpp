#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e) {
  cout << e << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
long long dp[100007], arr[100007];
long long solve(int asi) {
  if (asi > 100000) return 0;
  long long &ret = dp[asi];
  if (ret != -1ll) return ret;
  ret = solve(asi + 1);
  ret = max(ret, solve(asi + 2) + (asi * arr[asi]));
  return ret;
}
int main() {
  long long n, a;
  scanf(" %I64d", &n);
  while (n--) {
    scanf(" %I64d", &a);
    arr[a]++;
  }
  memset(dp, -1ll, sizeof(dp));
  printf("%I64d", solve(1));
  return 0;
}
