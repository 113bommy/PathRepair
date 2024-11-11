#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN];
bool vis[MAXN];
int len(int i) {
  if (vis[i]) return 0;
  vis[i] = true;
  return 1 + len(a[i]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < int(n); i++) {
    cin >> a[i];
    a[i]--;
  }
  vector<long long int> v;
  for (int i = 0; i < int(n); i++)
    if (!vis[i]) v.push_back(len(i));
  sort((v).begin(), (v).end());
  long long int ans = 0;
  int m = ((int)(v).size());
  if (m == 1)
    ans = v[0];
  else {
    for (int i = 0; i < int(m - 2); i++) ans += v[i] * v[i];
    ans += (v[m - 1] + v[m - 2]) * (v[m - 1] + v[m - 2]);
  }
  cout << ans << '\n';
  return 0;
}
