#include <bits/stdc++.h>
using namespace std;
enum color { BLACK, WHITE, GRAY };
signed main() {
  int i, j, k;
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int a[N + 1];
    for (i = 1; i <= N; i++) cin >> a[i];
    int lockd[N + 1];
    for (i = 1; i <= N; i++) cin >> lockd[i];
    vector<int> unlockd;
    for (i = 1; i <= N; i++) {
      if (!lockd[i]) {
        unlockd.push_back(a[i]);
      }
    }
    sort(unlockd.begin(), unlockd.end());
    int p = unlockd.size() - 1;
    int b[N + 1];
    int pref = 0;
    bool tri = true;
    int triv[N + 1];
    int nontriv[N + 1];
    for (i = 1; i <= N; i++) {
      if (lockd[i]) {
        pref += a[i];
        triv[i] = nontriv[i] = a[i];
      } else {
        pref += unlockd[p];
        triv[i] = unlockd[p];
        nontriv[i] = unlockd[unlockd.size() - 1 - p];
        p--;
      }
      if (pref < 0) {
        tri = false;
      }
    }
    if (tri) {
      for (i = 1; i <= N; i++) {
        printf("%d ", triv[i]);
      }
      printf("\n");
    } else {
      for (i = 1; i <= N; i++) {
        printf("%d ", triv[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
