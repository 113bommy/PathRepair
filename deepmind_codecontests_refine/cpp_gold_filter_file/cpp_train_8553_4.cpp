#include <bits/stdc++.h>
using namespace std;
inline long long n2(int n) { return (n * 1ll * (n + 1)) / 2; }
const int N = 2e5;
vector<int> f(N + 1);
long long get(int pos) {
  long long res = 0;
  for (; pos >= 0; pos = (pos & (pos + 1)) - 1) res += f[pos];
  return res;
}
long long get(int l, int r) { return get(r) - (l ? get(l - 1) : 0); }
void update(int pos, int val) {
  for (; pos < int(f.size()); pos |= pos + 1) f[pos] += val;
}
void solve() {
  int n;
  cin >> n;
  map<int, vector<int> > My;
  map<int, int> cntx;
  vector<int> indComp(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    indComp[i] = x;
    cntx[x]++;
    My[y].push_back(x);
  }
  sort(indComp.begin(), indComp.end());
  indComp.resize(unique(indComp.begin(), indComp.end()) - indComp.begin());
  for (pair<int, int> p : cntx) {
    int i =
        lower_bound(indComp.begin(), indComp.end(), p.first) - indComp.begin();
    update(i, 1);
  }
  long long ans = 0;
  for (auto &vp : My) {
    sort(vp.second.begin(), vp.second.end());
    int lst = -1;
    for (int x : vp.second) {
      int i = lower_bound(indComp.begin(), indComp.end(), x) - indComp.begin();
      int l = get(lst + 1, i);
      int r = get(i, N);
      ans += l * 1ll * r;
      lst = i;
      cntx[x]--;
      if (cntx[x] == 0) update(i, -1);
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1, tc = 1;
  while (T--) {
    solve();
  }
  return 0;
}
