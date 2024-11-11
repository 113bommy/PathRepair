#include <bits/stdc++.h>
using namespace std;
void fast() { ios::sync_with_stdio(false), cin.tie(0); }
const int S = 1e5 + 5;
int Vis[S];
int N[S];
const int S2 = 1e4 + 5;
int VV(int n) {
  int res = 0;
  while (n) {
    if (n & 1) {
      ++res;
    }
    n >>= 1;
  }
  return res;
}
int main() {
  fast();
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> N[i];
    ++Vis[N[i]];
  }
  long long ans = 0;
  if (k == 0) {
    for (int i = 0; i < S2; i++) {
      ans += (long long)(Vis[i] * (Vis[i] - 1)) / 2;
    }
    cout << ans << endl;
    return 0;
  }
  int maxx = *max_element(N, N + n);
  for (int i = 0; i <= maxx; i++) {
    if (!Vis[i]) {
      continue;
    }
    for (int j = i + 1; j <= maxx; j++) {
      if (!Vis[j]) {
        continue;
      }
      int U = i ^ j;
      if (k == VV(U)) {
        ans += (long long)Vis[i] * Vis[j];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
