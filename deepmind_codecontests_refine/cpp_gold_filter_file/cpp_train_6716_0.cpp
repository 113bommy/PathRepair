#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int ar[N], br[N];
vector<pair<long long, int> > va, vb;
int n, m, k;
long long s;
int pa, pb, pi;
bool fn(int md) {
  if (md == n) return 1;
  if (k <= va.size() && ar[md] * 1LL * va[k - 1].first <= s) {
    pa = ar[md];
    pi = k;
    return true;
  }
  if (k <= vb.size() && ar[md] * 1LL * vb[k - 1].first <= s) {
    pb = br[md];
    pi = 0;
    return true;
  }
  for (int i = 1; i < k; i++) {
    if (i <= va.size() && k - i <= vb.size() &&
        ar[md] * 1LL * va[i - 1].first + br[md] * 1LL * vb[k - i - 1].first <=
            s) {
      pa = ar[md];
      pb = br[md], pi = i;
      return true;
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> k >> s;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (i == 0)
      ar[i] = a;
    else
      ar[i] = min(ar[i - 1], a);
  }
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (i == 0)
      br[i] = a;
    else
      br[i] = min(br[i - 1], a);
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    if (a == 1)
      va.push_back({b, i + 1});
    else
      vb.push_back({b, i + 1});
  }
  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  for (int i = 1; i < va.size(); i++) va[i].first += va[i - 1].first;
  for (int i = 1; i < vb.size(); i++) vb[i].first += vb[i - 1].first;
  int l = 0, r = n;
  while (l < r) {
    int md = (l + r) / 2;
    if (fn(md))
      r = md;
    else
      l = md + 1;
  }
  r++;
  if (r == n + 1) {
    cout << -1 << "\n";
    return 0;
  }
  cout << r;
  cout << "\n";
  int i, j;
  i = j = 0;
  while (ar[i] != pa) i++;
  while (br[j] != pb) j++;
  int pki = k - pi;
  int y = 0, z = 0;
  while (y < pi && z < pki) {
    if (va[y].second < vb[z].second) {
      cout << va[y++].second << " " << i + 1;
    } else {
      cout << vb[z++].second << " " << j + 1;
    }
    cout << "\n";
  }
  while (y < pi) {
    cout << va[y++].second << " " << i + 1;
    cout << "\n";
  }
  while (z < pki) {
    cout << vb[z++].second << " " << j + 1;
    cout << "\n";
  }
}
