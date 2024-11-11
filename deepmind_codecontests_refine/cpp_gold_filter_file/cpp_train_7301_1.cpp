#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const long long mod = 1e9 + 7;
const int inf = 1e9 + 10;
const double D = 0.000001;
int a[N], b[N], chk[N] = {0}, hav[N] = {0};
vector<int> v;
set<int> S;
int main() {
  int m, k, s, n;
  cin >> m >> k >> n >> s;
  for (int i = 0; i < m; i++) scanf("%d", &a[i]);
  for (int i = 0; i < s; i++) {
    scanf("%d", &b[i]);
    chk[b[i]]++;
    S.insert(b[i]);
  }
  int l = 0, r = 0, cnt = S.size();
  for (int l = 0; l < m; l++) {
    while (r < m && cnt) {
      hav[a[r]]++;
      if (hav[a[r]] == chk[a[r]]) cnt--;
      r++;
    }
    if (cnt) break;
    if (m - l < k) break;
    int p = max(0, r - l - k);
    int q = l - ((l) / k) * k;
    int sum = p + q;
    if (m - sum >= n * k) {
      cout << sum << endl;
      for (int i = 0; i < q; i++) printf("%d ", i + 1);
      for (int i = l; i < r && p; i++) {
        if (hav[a[i]] - 1 >= chk[a[i]]) {
          hav[a[i]]--;
          printf("%d ", i + 1);
          p--;
        }
      }
      return 0;
    }
    hav[a[l]]--;
    if (hav[a[l]] < chk[a[l]]) cnt++;
  }
  cout << -1 << endl;
}
