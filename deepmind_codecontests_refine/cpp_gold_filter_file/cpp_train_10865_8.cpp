#include <bits/stdc++.h>
using namespace std;
int n, ans, b[1000001], a[2000000], p[2000000], h[10000001];
vector<int> t[10000001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (p[a[i]] == 0) p[a[i]] = i;
    h[a[i]]++;
    ans = max(h[a[i]], ans);
  }
  for (int i = 1; i <= n; i++) {
    memset(b, 0, sizeof(b));
    int l = i;
    for (int j = i + 1; j <= n; j++)
      if (a[j] == a[i]) {
        for (int k = l + 1; k < j; k++)
          if (b[p[a[k]]] % 2 == 1) b[p[a[k]]]++;
        l = j;
      } else if (b[p[a[j]]] % 2 == 0)
        b[p[a[j]]]++;
    for (int j = 1; j <= n; j++) ans = max(ans, b[j] + 1);
  }
  cout << ans;
}
