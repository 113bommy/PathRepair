#include <bits/stdc++.h>
using namespace std;
char v[200010], w[200010];
int t, n, i, j;
int aib1[30], aib2[30], f[30], f2[30], a[200010];
void update(int aib[], int p) {
  for (p; p <= 30; p += (p & -p)) aib[p]++;
}
int query(int aib[], int p) {
  int ans = 0;
  for (; p; p -= (p & -p)) ans += aib[p];
  return ans;
}
int main() {
  cin >> t;
  for (; t--;) {
    memset(f, 0, sizeof f);
    memset(f2, 0, sizeof f2);
    memset(aib1, 0, sizeof aib1);
    memset(aib2, 0, sizeof aib2);
    cin >> n;
    cin >> v + 1;
    for (i = 1; i <= n; i++) f[v[i] - 'a']++;
    cin >> w + 1;
    for (i = 1; i <= n; i++) f2[w[i] - 'a']++;
    int ok = 1;
    for (int i = 0; i <= 26; i++) {
      if (f[i] != f2[i]) {
        ok = 0;
        break;
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    ok = 0;
    for (i = 1; i <= n; i++) {
      if (w[i] == w[i - 1]) {
        ok = 1;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
      continue;
    }
    int inva = 0, invb = 0;
    for (i = 1; i <= n; i++) {
      update(aib1, v[i] - 'a' + 1);
      update(aib2, w[i] - 'a' + 1);
      inva += i - query(aib1, v[i] - 'a' + 1);
      invb += i - query(aib2, w[i] - 'a' + 1);
    }
    if (inva % 2 == invb % 2)
      cout << "YES\n";
    else {
      for (i = 1; i <= n; i++) a[i] = v[i] - 'a';
      sort(a + 1, a + n + 1);
      int ok = 0;
      for (i = 2; i <= n; i++)
        if (a[i] == a[i - 1]) {
          ok = 1;
          break;
        }
      if (ok)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
