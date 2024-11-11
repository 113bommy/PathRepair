#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, m, k, x, s;
  cin >> n >> m >> k >> x >> s;
  vector<pair<long long, long long> > Spells(m);
  vector<long long> C(k), D(k);
  for (int i = 0; i < m; i++) cin >> Spells[i].first;
  for (int i = 0; i < m; i++) cin >> Spells[i].second;
  for (int i = 0; i < k; i++) cin >> C[i];
  for (int i = 0; i < k; i++) cin >> D[i];
  long long answer = 1ll * n * x;
  for (int i = 0; i < m; i++)
    if (Spells[i].second + D[0] <= s) {
      int l = upper_bound(D.begin(), D.end(), (s - Spells[i].second)) -
              D.begin() - 1;
      answer = min(answer, 1ll * (n - C[l]) * Spells[i].first);
    } else if (Spells[i].second <= s && Spells[i].second + D[0] > s)
      answer = min(answer, 1ll * n * Spells[i].first);
  for (int i = 0; i < k; i++)
    if (D[i] <= s) answer = min(answer, 1ll * (n - C[i]) * x);
  cout << answer << endl;
  return 0;
}
