#include <bits/stdc++.h>
using namespace std;
int n;
int a[5000006];
int S;
void go(int lf, int rg) {
  if (lf < 0) return;
  S = max(S, (rg - lf) / 2);
  if (a[lf] == a[rg]) {
    for (int i = lf; i < rg; ++i) a[i] = a[lf];
  } else {
    for (int i = lf, j = rg; i < j; ++i, --j) {
      a[i] = a[lf];
      a[j] = a[rg];
    }
  }
}
void solve() {
  cin >> n;
  for (int i = 0; i < (n); ++i) scanf("%d", a + i);
  int lst = 0;
  S = 0;
  for (int i = 1; i <= (n - 2); ++i) {
    if (a[i] == a[i - 1] || a[i] == a[i + 1]) {
      if (i - lst > 1) go(lst, i);
      lst = i;
    }
  }
  if (n - 1 - lst > 1) go(lst, n - 1);
  cout << S << endl;
  for (int i = 0; i < (n); ++i) printf("%d", a[i]);
}
int main() {
  solve();
  return 0;
}
