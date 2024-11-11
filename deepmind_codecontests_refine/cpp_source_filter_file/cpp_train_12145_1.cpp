#include <bits/stdc++.h>
using namespace std;
int n, k, p;
int PDA[500005], DA[500005], A[500005], P[500005];
const int oo = 1e9 + 7;
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> k >> p;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) P[i] = (P[i - 1] + A[i]) % p;
  for (int i = 0; i < n + 2; i++) DA[i] = oo;
  DA[0] = 0;
  for (int cnt = 1; cnt <= k; cnt++) {
    pair<int, int> minda = {oo, 0};
    for (int i = 1; i <= n; i++)
      if (make_pair(DA[i], P[i]) < minda) {
        minda = {DA[i], P[i]};
        PDA[i] = i;
      } else
        PDA[i] = PDA[i - 1];
    for (int i = n; i > 0; i--) {
      int best = PDA[i - 1];
      DA[i] = DA[best] + (P[best] < P[i] ? 0 : 1);
    }
    DA[0] = oo;
  }
  cout << DA[n] * p + P[n] << endl;
}
