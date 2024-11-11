#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n;
vector<pair<int, int> > sol;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = (1); i <= (n); ++i) {
    int el;
    cin >> el;
    vector<int> holder(el);
    for (int i = (0); i < (el); ++i) {
      cin >> holder[i];
    }
    reverse(holder.begin(), holder.end());
    if (is_sorted(holder.begin(), holder.end())) {
      sol.emplace_back(pair<int, int>(holder[0], holder.back()));
    }
  }
  sort(sol.begin(), sol.end());
  long long ans = n * n;
  for (auto it : sol) {
    ans -= sol.end() -
           lower_bound(sol.begin(), sol.end(), pair<int, int>(it.second, -1));
  }
  cout << ans << '\n';
}
