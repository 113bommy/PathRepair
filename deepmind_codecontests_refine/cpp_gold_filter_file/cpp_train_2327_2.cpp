#include <bits/stdc++.h>
using namespace std;
long long n, m, k, a[1111111], b[1111111];
bool ok;
map<int, int> mp;
vector<int> v;
void add(int x) {
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == x) return;
  }
  v.push_back(x);
}
int f(int x) {
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == x) res++;
  }
  int need = 0;
  for (int i = 1; i <= n; ++i) {
    if (res >= n / 2) break;
    if (b[i] == x && a[i] != b[i]) {
      need++;
      res++;
    }
  }
  return need;
}
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  k = (n % 2);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    mp[a[i]]++;
    if (a[i] != b[i]) mp[b[i]]++;
    if (mp[a[i]] >= (n / 2) + k) {
      add(a[i]);
    }
    if (mp[b[i]] >= (n / 2) + k) {
      add(b[i]);
    }
  }
  if (n % 2 == 1) n++;
  if (v.size() == 0) return cout << -1, 0;
  int ans = 1e7;
  for (int i = 0; i < v.size(); ++i) {
    ans = min(ans, f(v[i]));
  }
  cout << ans;
}
