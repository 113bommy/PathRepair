#include <bits/stdc++.h>
using namespace std;
const int MX = 100000, N = 1000000, MOD = 1000000007;
const int INF = (int)1e9;
int pos[1005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, t;
  string A, T;
  while (cin >> a >> t) {
    cin >> A >> T;
    int mini = 100005;
    for (int i = (0); i <= (t - a); i++) {
      int cnt = 0;
      for (int j = (0); j <= (a - 1); j++) {
        if (T[i + j] != A[j]) cnt++;
      }
      if (cnt < mini) {
        mini = cnt;
        int k = 0;
        for (int j = (0); j <= (a - 1); j++) {
          if (T[i + j] != A[j]) {
            pos[k++] = j + 1;
          }
        }
      }
    }
    cout << mini << "\n";
    for (int i = (0); i <= (mini - 1); i++) {
      if (i > 0) cout << " ";
      cout << pos[i];
    }
    cout << "\n";
  }
  return 0;
}
