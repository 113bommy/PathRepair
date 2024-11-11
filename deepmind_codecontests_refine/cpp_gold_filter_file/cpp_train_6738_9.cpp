#include <bits/stdc++.h>
using namespace std;
int n, k, l, tab[100005], m;
long long suma = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k >> l;
  m = n * k;
  for (int i = 1; i <= m; i++) cin >> tab[i];
  sort(tab + 1, tab + m + 1);
  int wska = m, wskb = 1;
  while ((tab[wskb] <= tab[1] + l) && (wskb <= m)) wskb++;
  wskb--;
  if (wskb < n) {
    cout << 0 << endl;
    return 0;
  }
  int adolf = wskb;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j == k) {
        suma += tab[wskb];
        wskb--;
        if (wska == wskb + 1) wska--;
      } else {
        wska--;
        if (wska == adolf) wska = wskb;
        if (wska < wskb) wskb--;
      }
    }
  }
  cout << suma << endl;
  return 0;
}
