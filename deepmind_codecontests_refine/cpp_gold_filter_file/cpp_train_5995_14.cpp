#include <bits/stdc++.h>
using namespace std;
const int N = 1024;
int f[N], tmp[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k, x;
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    f[a]++;
  }
  for (int i = 1; i <= k; i++) {
    int countt = 0;
    for (int j = 0; j < N; j++) {
      tmp[j] = f[j];
    }
    for (int j = 0; j < N; j++) {
      if (f[j] > 0) {
        int xored = (j ^ x);
        int change = f[j] / 2;
        if (countt % 2 == 0) change += (f[j] & 1);
        tmp[j] -= change;
        tmp[xored] += change;
        countt += f[j];
      }
    }
    for (int j = 0; j < N; j++) {
      f[j] = tmp[j];
    }
  }
  k = k % 2;
  int mx, mn;
  mx = 0, mn = 1024;
  for (int i = 0; i < N; i++) {
    if (f[i] > 0) {
      mx = max(i, mx);
      mn = min(i, mn);
    }
  }
  cout << mx << " " << mn << endl;
  return 0;
}
