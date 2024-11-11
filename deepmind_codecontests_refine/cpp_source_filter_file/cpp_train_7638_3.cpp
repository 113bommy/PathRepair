#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, d;
  cin >> n >> m >> d;
  int sp = n * m;
  int a[sp];
  for (int i = 0; i < sp; i++) cin >> a[i];
  sort(a, a + sp);
  int mov = 0, mid = sp / 2 - 1;
  for (int i = 0; i < sp - 1; i++)
    if (a[i] % d != a[i + 1] % d) {
      cout << -1;
      return 0;
    } else
      mov += abs(a[i] - a[mid]) / d;
  mov += (a[sp - 1] - a[mid]) / d;
  cout << mov;
  return 0;
}
