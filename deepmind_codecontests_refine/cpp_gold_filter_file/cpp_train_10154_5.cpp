#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
constexpr int LG = 60;
int N;
long long int ai, bi, bs;
long long int x[LG + 1];
inline bool ins(long long int v) {
  for (int i = LG; i >= 0; --i) {
    if (!((v >> i) & 1)) continue;
    if (x[i]) {
      v ^= x[i];
    } else {
      for (int j = i - 1; j >= 0; --j)
        if ((v >> j) & 1) v ^= x[j];
      for (int j = i + 1; j <= LG; ++j)
        if ((x[j] >> i) & 1) x[j] ^= v;
      x[i] = v;
      return true;
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  int s = 0;
  for (int i = 0; i < N; ++i) {
    cin >> ai >> bi;
    bs ^= bi, ai ^= bi;
    if (ins(ai)) ++s;
  }
  for (int i = LG; i >= 0; --i)
    if ((bs >> i) & 1) bs ^= x[i];
  if (bs)
    cout << "1/1\n";
  else
    cout << (1ll << s) - 1 << '/' << (1ll << s) << '\n';
  return 0;
}
