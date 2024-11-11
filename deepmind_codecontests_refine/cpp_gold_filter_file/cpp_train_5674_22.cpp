#include <bits/stdc++.h>
using namespace std;
long long n, m, Max, k, vt, f[110];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (long long i = (1), _b = (m); i <= _b; i++) {
    Max = -1;
    for (long long j = (1), _b = (n); j <= _b; j++) {
      cin >> k;
      if (k > Max) {
        Max = k;
        vt = j;
      }
    }
    f[vt]++;
  }
  Max = -1;
  for (long long i = (1), _b = (n); i <= _b; i++)
    if (f[i] > Max) {
      Max = f[i];
      vt = i;
    }
  cout << vt;
  return 0;
}
