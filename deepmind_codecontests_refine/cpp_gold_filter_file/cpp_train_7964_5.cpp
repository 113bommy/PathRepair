#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pair<int, int> > V(n);
  for (int i = 0; i < n; i++) {
    cin >> V[i].first;
    V[i].second = i;
  }
  sort(V.begin(), V.end());
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    ans += abs(V[i].second - V[i - 1].second);
  }
  cout << ans << "\n";
}
