#include <bits/stdc++.h>
using namespace std;
using ll = signed long long int;
using pi = pair<int, int>;
using vi = vector<int>;
const int N = 3e5 + 100;
vi fp[N];
int a[N], n, m, x, y, li, idx[N];
ll res;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    idx[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    fp[x].push_back(y);
    fp[y].push_back(x);
  }
  for (ll i = 0; i < n; i++) {
    for (auto x : fp[a[i]]) {
      if (idx[x] <= i) {
        li = max(li, idx[x] + 1);
      }
    }
    res += i - li + 1LL;
  }
  cout << res;
}
