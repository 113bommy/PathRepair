#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int sp[1000005];
void sieve() {
  const int N = 1e6 + 1;
  for (int i = 2; i * i < N; i++) {
    if (sp[i]) continue;
    sp[i] = i;
    for (int j = i * i; j < N; j += i) {
      sp[j] = i;
    }
  }
  for (int i = 2; i < N; i++) {
    if (!sp[i]) sp[i] = i;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int i, j, k, l, m, n, t, r, cnt, x2;
  int flag = 0;
  long long ans = 0, an = 0;
  t = 1;
  sieve();
  while (t--) {
    cin >> x2;
    n = x2;
    set<int> se;
    while (n > 1) {
      se.insert(sp[n]);
      n /= sp[n];
    }
    l = *se.rbegin();
    int div = x2 / l;
    int st = (div - 1) * l + 1;
    int en = x2;
    int ma, x0 = x2;
    for (i = st; i <= en; i++) {
      se.clear();
      n = i;
      if (sp[i] == i) continue;
      while (n > 1) {
        se.insert(sp[n]);
        n /= sp[i];
      }
      ma = *se.rbegin();
      x0 = min(x0, ((i / ma) - 1) * ma + 1);
    }
    cout << x0 << endl;
  }
}
