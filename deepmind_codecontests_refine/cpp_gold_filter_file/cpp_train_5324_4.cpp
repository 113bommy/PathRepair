#include <bits/stdc++.h>
using namespace std;
const int N = 500100;
int m, k, n, s, a[N];
int need[N], have[N], cnt, cool[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k >> m >> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int diff = 0;
  for (int i = 1; i <= s; i++) {
    int x;
    cin >> x;
    cool[x] = 1;
    if (++need[x] == 1) ++diff;
  }
  int r = -1;
  int kolDelete = n - k * m;
  int tl = -1, tr = -1;
  int kol = 0;
  for (int i = 0; i < n; i++) {
    if (i + k > n) break;
    while (r + 1 < n && ((r - i + 1) < k || kol < diff)) {
      ++r;
      if (cool[a[r]]) {
        if (++have[a[r]] == need[a[r]]) ++kol;
      }
    }
    if (kol < diff) break;
    int needd = i % k + r - i + 1 - k;
    if (needd <= kolDelete) {
      tl = i;
      tr = r;
      break;
    }
    if (cool[a[i]]) {
      if (have[a[i]] == need[a[i]]) --kol;
      --have[a[i]];
    }
  }
  if (tl == -1) return cout << -1, 0;
  vector<int> vec;
  for (int i = 0; i < tl % k; i++) {
    vec.push_back(i + 1);
    --kolDelete;
  }
  memset(have, 0, sizeof(have));
  kol = 0;
  for (int i = tl; i < n; i++) {
    if (cool[a[i]] && have[a[i]] < need[a[i]]) {
      ++have[a[i]];
    } else {
      if (kolDelete) {
        --kolDelete;
        vec.push_back(i + 1);
      }
    }
  }
  if (kolDelete != 0) return cout << -1, 0;
  cout << vec.size() << "\n";
  for (int i = 0; i < vec.size(); i++) cout << vec[i] << ' ';
}
