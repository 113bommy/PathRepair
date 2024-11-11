#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > tab(n);
  vector<int> skill(n);
  for (int i = 0; i < n; i++) {
    cin >> tab[i].first;
    skill[i] = tab[i].first;
    tab[i].second = i;
  }
  sort((tab).begin(), (tab).end());
  vector<int> res(n);
  int ile = 0, teSame = 0, war = 0;
  for (int i = 0; i < n; i++) {
    res[tab[i].second] = ile;
    if (war != tab[i].first) {
      res[tab[i].second] += teSame;
    }
    if (i == 0 || war != tab[i].first) {
      ile += teSame;
      teSame = 1;
      war = tab[i].first;
    } else
      teSame++;
  }
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (skill[b] > skill[a]) swap(a, b);
    if (skill[a] >= skill[b]) {
      res[a]--;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  return 0;
}
