#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N], b[N], d[N], id[N];
vector<int> c[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(a + 1, a + 1 + m * n);
    int num = unique(a + 1, a + 1 + m * n) - a - 1;
    for (int i = 1; i <= num; i++) {
      c[i].clear();
    }
    for (int i = 1; i <= n * m; i++) {
      int tt = lower_bound(a + 1, a + 1 + num, b[i]) - a;
      c[tt].push_back(i);
    }
    int ans = 0, now = 1;
    for (int i = 1; i <= num; i++) {
      int len = (m - (now - 1) % m);
      if (c[i].size() > len) {
        for (int j = now; j <= m; j++) {
          id[(j - 1) % m + 1] = c[i][now - j + len - 1];
        }
        for (int j = now; j <= m; j++) {
          for (int k = 1; k < now; k++) {
            if (id[k] < id[j]) ans++;
          }
        }
        int mm = c[i].size(), st;
        st = mm;
        mm -= len;
        mm %= m;
        now = mm + 1;
        for (int j = 1; j <= mm; j++) {
          id[j] = c[i][st - j];
        }
      } else {
        int mm = c[i].size();
        for (int j = now; j < now + mm; j++) {
          id[(j - 1) % m + 1] = c[i][mm - (j - now + 1)];
        }
        for (int j = now; j < now + mm; j++) {
          for (int k = 1; k < now; k++) {
            if (id[k] < id[j]) ans++;
          }
        }
        now += mm;
        now = (now - 1) % m + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
