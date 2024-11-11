#include <bits/stdc++.h>
using namespace std;
int T, H, N;
int p[300005];
int main() {
  ios::sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> H >> N;
    for (int i = 1; i <= N; i++) {
      cin >> p[i];
    }
    int ans = 0;
    for (int i = 1; i < N; i++) {
      if (i == N - 1) {
        if (p[i] <= 2 || p[i + 1] <= 2) continue;
        ++ans;
      } else {
        if (p[i + 1] == p[i + 2] + 1)
          i++;
        else {
          p[i + 1]--;
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
