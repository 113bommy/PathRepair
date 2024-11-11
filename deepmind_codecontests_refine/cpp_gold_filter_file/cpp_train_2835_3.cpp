#include <bits/stdc++.h>
#pragma GCC target("sse4.2")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int t[N];
    for (int i = 0; i < N; i++) cin >> t[i];
    bool possible = true;
    int parity = (t[0] & 1);
    for (int i = 1; i < N; i++) {
      if (parity != (t[i] & 1)) {
        possible = false;
        break;
      }
    }
    cout << (possible ? "YES\n" : "NO\n");
  }
  return 0;
}
