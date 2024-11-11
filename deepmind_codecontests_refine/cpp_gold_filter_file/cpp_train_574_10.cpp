#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  std::vector<std::pair<int, int> > ice;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    ice.push_back(make_pair(x, y));
  }
  sort((ice).begin(), (ice).end());
  std::vector<std::pair<int, int> > evx;
  for (int i = 0; i < n; i++) {
    evx.push_back(make_pair(ice[i].first + k, i));
    evx.push_back(make_pair(ice[i].first, i));
  }
  std::vector<int> u(n, 0);
  sort((evx).begin(), (evx).end());
  multiset<std::pair<int, int> > evy;
  std::vector<long long> ans(n + 1, 0);
  for (int proc = 0; proc < 2 * n - 1; proc++) {
    int i = evx[proc].second;
    if (u[i] == 0) {
      evy.insert(make_pair(ice[i].second, 1));
      evy.insert(make_pair(ice[i].second + k, -1));
      u[i] = 1;
    } else {
      evy.erase(evy.find(make_pair(ice[i].second, 1)));
      evy.erase(evy.find(make_pair(ice[i].second + k, -1)));
      u[i] = 0;
    }
    long long krat = evx[proc + 1].first - evx[proc].first;
    if (krat == 0) continue;
    int num = 0;
    int prevy = 0;
    for (auto u : evy) {
      ans[num] += (u.first - prevy) * krat;
      prevy = u.first;
      num += u.second;
    }
  }
  for (int i = 1; i < n + 1; i++) printf("%lld ", ans[i]);
}
