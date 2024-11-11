#include <bits/stdc++.h>
const long long maxn = 1e5 + 10;
const long long mod = 1e9 + 7;
const long long inf = 2e18;
const long long delta = 10169;
using namespace std;
int bin[40], bin2[40];
int tam(int a) {
g:
  if (bin[a] > 0) return 0;
  if (bin[a + 1] > 0) {
    bin[a + 1]--;
    bin[a] += 2;
  } else if (a < 38) {
    if (tam(a + 1) == 0) goto g;
  } else {
    return -1;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int b = floor(log2(a));
    for (int j = 0; j <= b; j++) {
      if (a % 2 == 1) bin[j]++;
      a /= 2;
    }
  }
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    bin2[a]++;
  }
  int ans = 0;
  for (int i = 0; i < 40; i++) {
    while (bin2[i] > 0) {
    h:
      while (bin[i] > 0 && bin2[i] > 0) {
        bin2[i]--;
        bin[i]--;
        ans++;
      }
      if (bin[i] == 0 && tam(i) != -1) goto h;
      goto l;
    }
  l:;
  }
  cout << ans;
  return 0;
}
