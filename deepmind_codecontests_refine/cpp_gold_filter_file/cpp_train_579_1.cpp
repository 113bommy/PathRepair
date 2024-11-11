#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int cnt[101010];
vector<long long> szs;
long long a, b;
int ans = inf;
int ok(long long w, long long h) {
  if (a <= w && b <= h) return 1;
  if (a <= h && b <= w) return 1;
  return 0;
}
void go(long long w, long long h, int i, int c) {
  if (ok(w, h)) {
    ans = min(ans, c);
    return;
  }
  if (i >= (int)szs.size()) return;
  long long nw = w;
  long long tx = szs[i];
  for (int t1 = 0; t1 <= cnt[szs[i]]; t1++) {
    long long nh = h;
    for (int t2 = 0; t2 + t1 <= cnt[szs[i]]; t2++) {
      if (ok(nw, nh)) {
        go(nw, nh, i + 1, c + t1 + t2);
        break;
      } else {
        if (t1 + t2 == cnt[szs[i]]) {
          go(nw, nh, i + 1, c + t1 + t2);
        }
      }
      if (nh > a && nh > b) break;
      nh *= tx;
    }
    if (nw > a && nw > b) break;
    nw *= tx;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long w, h;
  cin >> a >> b >> w >> h;
  if (a <= w && b <= h) ans = 0;
  if (a <= h && b <= w) ans = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long s;
    cin >> s;
    cnt[s]++;
    szs.push_back(s);
  }
  sort(szs.rbegin(), szs.rend());
  szs.erase(unique(szs.begin(), szs.end()), szs.end());
  go(w, h, 0, 0);
  if (ans >= inf) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
