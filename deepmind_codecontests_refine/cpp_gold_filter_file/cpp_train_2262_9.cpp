#include <bits/stdc++.h>
using namespace std;
int II() {
  int q;
  scanf("%d", &q);
  return q;
}
void solve() {
  int N;
  cin >> N;
  int ar[N + N + 100];
  N = N + N;
  for (int i = 1; i <= N; i++) {
    cin >> ar[i];
  }
  int ans = 0;
  for (int i = N; i > 1; i -= 2) {
    if (ar[i] == ar[i - 1])
      continue;
    else {
      int j = i - 1;
      for (; j >= 1; j--) {
        if (ar[j] == ar[i]) break;
      }
      for (int k = j; k < i - 1; k++) {
        swap(ar[k], ar[k + 1]);
        ans++;
      }
    }
  }
  cout << ans << endl;
}
int32_t main() {
  int tt;
  tt = 1;
  int cas = 1;
  while (tt--) {
    solve();
  }
}
