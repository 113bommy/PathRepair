#include <bits/stdc++.h>
using namespace std;
long long int em(long long int x, long long int Mod, long long int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return em((x % Mod * x % Mod) % Mod, Mod, n / 2) % Mod;
  else
    return (x % Mod * em((x % Mod * x % Mod) % Mod, Mod, (n - 1) / 2)) % Mod;
}
long long int fq[10000002];
long long int idx[10000002][2];
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, i, j, k, l;
  cin >> n;
  long long int arr[n + 1];
  memset(idx, -1, sizeof(idx));
  for (long long int i = (long long int)1; i < (long long int)n + 1; i++) {
    cin >> arr[i];
    fq[arr[i]]++;
    if (idx[arr[i]][0] == -1)
      idx[arr[i]][0] = i;
    else if (idx[arr[i]][1] == -1)
      idx[arr[i]][1] = i;
  }
  long long int a = -1, b = -1, ans = 1e18;
  for (long long int i = (long long int)1; i < (long long int)10000002; i++) {
    long long int cura = -1, curb = -1;
    for (j = i; j < 10000002; j += i) {
      long long int f = fq[j];
      if (cura != -1 && curb != -1) break;
      while (f > 0) {
        if (cura == -1)
          cura = j;
        else if (curb == -1)
          curb = j;
        else
          break;
        f--;
      }
    }
    if (cura == -1 || curb == -1) continue;
    if (((cura * curb) / i) < ans) {
      ans = ((cura * curb) / i);
      if (cura == curb) {
        a = idx[cura][0];
        b = idx[cura][1];
      } else {
        a = idx[cura][0];
        b = idx[curb][0];
      }
    }
  }
  cout << min(a, b) << " " << max(a, b) << "\n";
}
