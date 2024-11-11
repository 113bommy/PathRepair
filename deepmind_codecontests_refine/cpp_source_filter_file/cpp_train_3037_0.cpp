#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
class {
 public:
  int S[200009], N;
  void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> S[i];
    for (int i = 1; i <= N; i++) S[i] = S[i - 1] + S[i];
    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      cout << (S[r] - S[l]) / 10 << "\n";
    }
  }
} NSPACE;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}
