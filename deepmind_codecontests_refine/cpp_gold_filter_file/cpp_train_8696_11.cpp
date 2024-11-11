#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, a[N];
vector<pair<long long, long long> > v[N];
bool b[N];
int ans = 0;
void init() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  long long pi, ci;
  for (int i = 2; i <= n; ++i) {
    cin >> pi >> ci;
    v[pi].push_back(make_pair(i, ci));
    v[i].push_back(make_pair(pi, ci));
  }
}
void go(long long index, long long dst, long long m, bool sad) {
  if (b[index] == true)
    return;
  else
    b[index] = true;
  if (dst - m > a[index]) sad = true;
  if (sad == true) ++ans;
  for (int i = 0; i < v[index].size(); ++i)
    go(v[index][i].first, dst + v[index][i].second,
       min(m, dst + v[index][i].second), sad);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init();
  go(1, 0, 0, false);
  cout << ans << endl;
}
