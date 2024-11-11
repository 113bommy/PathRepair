#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
const int mod = (int)1e9 + 7;
const int logN = 18;
const int inf = 1e9;
const int N = 2e5 + 5;
int n, k, m, t, x;
string str[N];
map<int, int> h;
pair<int, int> a[N];
bool add(int k, int l, int s) {
  if (h[k] == 2) return 0;
  if (l == 0) return h[k] = 2;
  h[k] = 1;
  if (add((k + k), l - 1, s)) {
    str[s] += '0';
    return 1;
  }
  if (add((k + k + 1), l - 1, s)) {
    str[s] += '1';
    return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a[i] = make_pair(x, i);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if (!add(1, a[i].first, a[i].second)) {
      cout << "NO " << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  for (int i = 1; i <= n; i++) {
    reverse(str[i].begin(), str[i].end());
    cout << str[i] << '\n';
  }
  return 0;
}
