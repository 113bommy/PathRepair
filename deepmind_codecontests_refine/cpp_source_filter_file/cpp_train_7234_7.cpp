#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1e5 + 17;
int t[Nmax], res[Nmax];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) cin >> t[i];
  int worst = 0;
  for (int i = 1; i <= n; i++) {
    worst = min(worst, t[i] - 1);
    res[i] = worst + i;
  }
  worst = n + 1;
  for (int i = n; i >= 1; i--) {
    worst = min(worst, t[i] + 1);
    res[i] = min(res[i], worst - i);
  }
  int r = 0;
  for (int i = 1; i <= n; i++) r = max(r, res[i]);
  cout << r;
}
