#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1e5 + 5;
const int Mod = 666013;
const int oo = 1e9 + 1;
int T;
int main() {
  cin >> T;
  while (T--) {
    int n;
    vector<pair<int, int> > v;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      sum += x;
      v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    int mx = (*v.rbegin()).first;
    sum -= mx;
    if (mx >= sum) {
      cout << sum << "\n";
      for (auto e : v)
        while (sum > 0 && e.first > 0)
          sum--, e.first--,
              cout << e.second << " " << (*v.rbegin()).second << "\n";
    } else {
      int k = 0;
      pair<int, int> sol[Nmax];
      for (int i = 0; i < v.size(); i++)
        if (v[i].first > 0) {
          while (sum - 2 >= mx && v[i].first > 0) {
            k++;
            sol[k] = {v[i].second, v[i + 1].second};
            sum -= 2;
            v[i].first--;
            v[i + 1].first--;
          }
        }
      for (auto e : v)
        while ((sum > 0 || mx > 0) && e.first > 0)
          mx--, sum--, e.first--, k++,
              sol[k] = {e.second, (*v.rbegin()).second};
      cout << k << "\n";
      for (int i = 1; i <= k; i++)
        cout << sol[i].first << " " << sol[i].second << "\n";
    }
  }
  return 0;
}
