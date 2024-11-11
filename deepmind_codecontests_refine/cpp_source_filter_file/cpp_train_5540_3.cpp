#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
long long pw(long long b, long long p) {
  if (!p) return 1;
  long long sq = pw(b, p / 2) % 1000000007;
  sq = (sq * sq) % 1000000007;
  if (p % 2) sq = (sq * b) % 1000000007;
  return sq;
}
const int N = 1e6 + 10, M = 0;
int Zarr[N];
string s;
void getZarr() {
  memset(Zarr, 0, sizeof Zarr);
  int n = (int)s.size();
  int r, l, k;
  l = r = 0;
  for (int i = 1; i < n; i++) {
    if (i > r) {
      l = r = i;
      while (s[r - l] == s[r] && r < n) r++;
      Zarr[i] = r - l;
      r--;
    } else {
      k = i - l;
      if (Zarr[k] < r - i + 1) {
        Zarr[i] = Zarr[k];
      } else {
        l = i;
        while (r < n && s[r - l] == s[r]) r++;
        Zarr[i] = r - l;
        r--;
      }
    }
  }
}
int mp[N], ex[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  getZarr();
  int mx = 0;
  bool ok = 0;
  int t = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    if (Zarr[i] && ((Zarr[i + Zarr[i]] == Zarr[i]) ||
                    ((i + Zarr[i] != (int)s.size()) ||
                     ((i + Zarr[i] == (int)s.size() && ok))))) {
      if (Zarr[(int)s.size() - Zarr[i]] == Zarr[i] && (t > Zarr[i])) {
        mx = max(mx, Zarr[i]);
      }
    }
    if (Zarr[i]) ok = 1;
    t = max(t, Zarr[i]);
  }
  if (!mx) {
    cout << "Just a legend";
    return 0;
  }
  string res = s.substr(0, mx);
  cout << res;
  return 0;
}
