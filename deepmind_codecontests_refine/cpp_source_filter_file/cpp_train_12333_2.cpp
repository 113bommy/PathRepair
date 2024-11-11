#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, r, avg;
  cin >> n >> r >> avg;
  long long goal = n * avg, sum = 0;
  vector<pair<int, int> > gra;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    sum += 1ll * a;
    gra.push_back({b, a});
  }
  sort(gra.begin(), gra.end());
  long long ans = 0;
  int pos = 0;
  while (pos < gra.size() && sum < goal) {
    int ess = gra[pos].first, grad = gra[pos].second;
    long long cant = min(goal - sum, 1ll * (r - grad));
    sum += cant;
    ans += 1ll * ess * cant;
    pos++;
  }
  cout << ans << '\n';
}
