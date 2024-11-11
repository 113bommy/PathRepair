#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  long long x, s;
  cin >> x >> s;
  vector<pair<long long, long long> > V(m), V2(k);
  for (int i = 0; i < m; i++) cin >> V[i].second;
  for (int i = 0; i < m; i++) cin >> V[i].first;
  V.push_back(make_pair(0, x));
  sort(V.begin(), V.end());
  for (int i = 1; i < m; i++)
    if (V[i - 1].second < V[i].second) V[i].second = V[i - 1].second;
  for (int i = 0; i < k; i++) cin >> V2[i].second;
  for (int i = 0; i < k; i++) cin >> V2[i].first;
  V2.push_back(make_pair(0, 0));
  unsigned long long sol = 1LL << 63;
  for (int i = 0; i <= k; i++) {
    int pos = upper_bound(V.begin(), V.end(), make_pair(s - V2[i].first, x)) -
              V.begin();
    pos--;
    if (pos < 0) continue;
    unsigned long long aux = n - V2[i].second;
    sol = min(sol, aux * V[pos].second);
  }
  cout << sol << '\n';
  return 0;
}
