#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 100;
int N, arr[MAX_N], K[MAX_N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  cin >> N;
  for (int z = 0; z < N; ++z) cin >> arr[z];
  int hi, lo, par;
  for (int v = 1; v <= N - 1; ++v) {
    int p;
    for (p = 0; p * p <= v - 1; ++p) {
      hi = p == 0 ? N - 1 : (v - 1) / p;
      lo = (v - 1) / (p + 1);
      if (arr[v] < arr[p]) {
        K[lo + 1]++;
        K[hi + 1]--;
      }
    }
    for (int k = 1; k <= (v - 1) / p; ++k) {
      par = (v - 1) / k;
      if (arr[v] < arr[par]) ++K[k], --K[k + 1];
    }
  }
  int ans = 0;
  for (int k = 1; k <= N - 1; ++k) {
    ans += K[k];
    cout << ans << ' ';
  }
  cout << endl;
}
