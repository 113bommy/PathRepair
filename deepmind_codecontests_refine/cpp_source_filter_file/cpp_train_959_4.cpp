#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
ll calc(vector<int> &a, int l, int r) {
  int n = a.size();
  ll ans = 0;
  vi aux;
  for (int i = 0; i < n; i++) {
    auto upp = upper_bound(aux.begin(), aux.end(), r - a[i]);
    auto lww = lower_bound(aux.begin(), aux.end(), l - a[i]);
    int up = upp - aux.begin() - 1;
    int lw = lww - aux.begin();
    if (lw < i && up < i && lw <= up) {
      ans += up - lw + 1;
    }
    aux.push_back(a[i]);
  }
  return ans;
}
void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int powi = 2;
  vector<int> ans(30, 0);
  for (int i = 0; i < 3; i++) {
    ll qtd = 0;
    vi amod(n);
    for (int i = 0; i < n; i++) {
      amod[i] = a[i] % powi;
    }
    sort(amod.begin(), amod.end());
    int left = powi / 2;
    int right = powi - 1;
    qtd += calc(amod, left, right);
    left = powi + powi / 2;
    right = powi * 2 - 2;
    qtd += calc(amod, left, right);
    ans[i] = qtd % 2;
    powi *= 2;
  }
  ll ans1 = 0;
  for (int i = 29; i >= 0; i--) {
    ans1 = ans[i] + ans1 * 2;
  }
  cout << ans1 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
