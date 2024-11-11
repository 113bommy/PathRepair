#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
long long msk[N];
int n, val[N];
inline void read_input() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> val[i] >> msk[i];
}
inline void solve() {
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += val[i];
  if (sum < 0)
    for (int i = 0; i < n; i++) val[i] *= -1;
}
inline void write_output() {
  long long x = 0;
  for (int i = 0; i < 62; i++) {
    long long cur = 0;
    for (int j = 0; j < n; j++)
      if (msk[j] >> i & 1 && msk[j] < 2 << i) cur += val[j];
    if (cur > 0) {
      for (int j = 0; j < n; j++)
        if (msk[j] >> i & 1) val[j] *= -1;
      x |= 1LL << i;
    }
  }
  cout << x;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), solve(), write_output();
  return 0;
}
