#include <bits/stdc++.h>
using namespace std;
int inf_int = 1e9;
long long inf_ll = 1e18;
const double pi = 3.1415926535898;
bool debug = 0;
const int maxn = 5e5 + 10;
int mod = 1e9;
int mn[maxn];
int res[maxn];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    mn[i] = inf_int;
  }
  for (int i = 0; i < 10; i++) {
    vector<int> a;
    for (int e = 1; e <= n; e++) {
      if ((e >> i) & 1) {
        a.push_back(e);
      }
    }
    if (a.size() == 0) continue;
    cout << a.size() << "\n";
    for (int v : a) {
      cout << v << " ";
    }
    cout << endl;
    int res;
    for (int e = 1; e <= n; e++) {
      cin >> res;
      if ((e >> i) & 1) {
        continue;
      }
      mn[e] = min(mn[e], res);
    }
  }
  for (int i = 0; i < 10; i++) {
    vector<int> a;
    for (int e = 1; e <= n; e++) {
      if (((e >> i) & 1) == 0) {
        a.push_back(e);
      }
    }
    if (a.size() == 0) continue;
    cout << a.size() << "\n";
    for (int v : a) {
      cout << v << " ";
    }
    cout << endl;
    int res;
    for (int e = 1; e <= n; e++) {
      cin >> res;
      if (((e >> i) & 1) == 0) {
        continue;
      }
      mn[e] = min(mn[e], res);
    }
  }
  cout << "-1\n";
  for (int i = 1; i <= n; i++) {
    cout << mn[i] << " ";
  }
  cout << endl;
}
int main() {
  if (!debug) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int t = 1;
  while (t--) solve();
  return 0;
}
