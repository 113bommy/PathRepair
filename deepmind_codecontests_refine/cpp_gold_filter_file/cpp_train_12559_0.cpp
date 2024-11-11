#include <bits/stdc++.h>
const double eps = (1e-10);
using namespace std;
int dcmp(double a, double b) {
  return fabs(a - b) <= eps ? 0 : (a > b) ? 1 : -1;
}
long long getBit(long long num, int idx) { return ((num >> idx) & 1ll) == 1ll; }
long long setBit1(long long num, int idx) { return num | (1ll << idx); }
long long setBit0(long long num, int idx) { return num & ~(1ll << idx); }
long long flipBit(long long num, int idx) { return num ^ (1ll << idx); }
int countNumBit1(long long mask) {
  int ret = 0;
  while (mask) {
    mask &= (mask - 1ll);
    ++ret;
  }
  return ret;
}
int ans[1000 + 5], L[1000 + 9], R[1000 + 9];
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(ans, 0, sizeof(ans));
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> L[i] >> R[i];
    }
    int tm = 1;
    for (int i = 0; i < n; i++) {
      int arr = L[i];
      int lv = R[i];
      if (arr >= tm) {
        tm = arr + 1;
        ans[i] = arr;
      } else if (tm > lv) {
        ans[i] = 0;
      } else {
        ans[i] = tm;
        tm++;
      }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
  }
}
