#include <bits/stdc++.h>
using namespace std;
long long int n, d, a, b, x, y;
vector<pair<int, int> > vect;
vector<int> ans;
int main() {
  cin >> n >> d >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    vect.push_back({x * a + y * b, i});
  }
  sort(vect.begin(), vect.end());
  for (int i = 0; i < n; i++) {
    if (d < vect[i].first) break;
    ans.push_back(vect[i].second);
    d -= vect[i].first;
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << ' ';
}
