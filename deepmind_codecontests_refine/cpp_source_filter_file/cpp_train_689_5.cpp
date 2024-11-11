#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = pow(10, 18) + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d;
  cin >> n >> d;
  int zzh[n];
  for (int i = 0; i < n; i += 1) cin >> zzh[i];
  int final_ans = MOD;
  sort(zzh, zzh + n);
  if (zzh[n - 1] - zzh[0] == d) {
    cout << 0 << "\n";
    exit(0);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (zzh[j] - zzh[i] == d) final_ans = min(final_ans, (i + (n - j - 1)));
    }
  }
  cout << final_ans << "\n";
  return 0;
}
