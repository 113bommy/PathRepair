#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int mod = 1e9 + 7;
struct triple {
  long long ff, ss, th;
};
bool comp(triple x, triple y) { return x.ff < y.ff; }
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<triple> va, vb;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
    for (int j = 0; j < i; j++) {
      va.push_back({a[i] + a[j], j, i});
    }
  }
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    s -= b[i];
    for (int j = 0; j < i; j++) {
      vb.push_back({b[i] + b[j], j, i});
    }
  }
  long long mn = abs(s), k = 0;
  vector<pair<int, int> > ans(2);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long dif = s - 2 * a[i] + 2 * b[j];
      if (abs(dif) < mn) {
        mn = abs(dif);
        k = 1;
        ans[0] = {i, j};
      }
    }
  }
  sort(va.begin(), va.end(), comp);
  sort(vb.begin(), vb.end(), comp);
  for (int i = 0, j = 0; i < va.size() && j < vb.size();) {
    long long dif = s - 2 * va[i].ff + 2 * vb[j].ff;
    if (abs(dif) < mn) {
      mn = abs(dif);
      k = 2;
      ans[0] = {va[i].ss, vb[j].ss};
      ans[1] = {va[i].th, vb[i].th};
    }
    if (dif < 0)
      j++;
    else
      i++;
  }
  cout << mn << endl;
  cout << k << endl;
  for (int i = 0; i < k; i++) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  }
}
