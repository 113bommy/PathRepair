#include <bits/stdc++.h>
using namespace std;
const int maxk = 17;
const int maxn = 1e5 + 17;
int T;
int A, B, C, D, K;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> A >> B >> C >> D >> K;
    bool ans = false;
    for (int i = 0; i <= K; i++)
      if (i * C >= A && (K - i) * D >= B) {
        ans = true;
        cout << i << " " << (K - i) << endl;
        break;
      }
    if (!ans) cout << -1 << endl;
  }
  return 0;
}
