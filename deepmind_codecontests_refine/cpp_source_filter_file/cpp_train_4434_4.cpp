#include <bits/stdc++.h>
using namespace std;
int n;
int x[100010];
int y[100010];
long long sumx, sumy;
int main() {
  cin >> n;
  sumx = 0;
  sumy = 0;
  for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 0; i < n; i++) sumx += (long long)x[i];
  for (int i = 0; i < n; i++) sumy += (long long)y[i];
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res += (long long)x[i] * (long long)x[i] * (long long)(n - 1) -
           (long long)x[i] * (long long)(sumy - y[i]);
    res += (long long)y[i] * (long long)y[i] * (long long)(n - 1) -
           (long long)x[i] * (long long)(sumy - y[i]);
  }
  cout << res << endl;
  return 0;
}
