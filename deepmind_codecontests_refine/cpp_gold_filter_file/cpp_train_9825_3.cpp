#include <bits/stdc++.h>
using namespace std;
int n, q, c, C[100010], V[100010], L, H;
long long F[100010], A, B, a, b, s;
int main() {
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> V[i];
  for (int i = 0; i < n; ++i) cin >> C[i];
  for (int j = 0; j < q; ++j) {
    for (int i = 0; i < 100010; ++i) F[i] = -1ll << 50;
    cin >> a >> b, L = H = F[0] = 0;
    for (int i = 0; i < n; ++i) {
      c = C[i], A = V[i] * a, B = V[i] * b, s = -1ll << 50;
      s = max(s, max(H != c ? F[H] : F[L], 0ll) + B);
      if (F[c] != -1ll << 50) s = max(s, F[c] + A);
      if (s > F[c]) {
        F[c] = s;
        if (c == L || c == H) {
          if (F[L] > F[H]) L ^= H ^= L ^= H;
        } else {
          if (F[c] > F[H])
            L = H, H = c;
          else if (F[c] > F[L])
            L = c;
        }
      }
    }
    cout << F[H] << endl;
  }
}
