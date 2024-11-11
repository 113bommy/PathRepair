#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, m, x[N], y[N];
map<int, int> Count;
int main() {
  cin >> n;
  for (int i = 1, _b = (n); i <= _b; i++) {
    int x;
    cin >> x;
    Count[x]++;
  }
  cin >> m;
  pair<int, int> best;
  int ans = 0;
  for (int i = 1, _b = (m); i <= _b; i++) {
    cin >> x[i];
  }
  for (int i = 1, _b = (m); i <= _b; i++) cin >> y[i];
  for (int i = 1, _b = (m); i <= _b; i++) {
    if (best <= make_pair(Count[x[i]], Count[y[i]])) {
      best = make_pair(Count[x[i]], Count[y[i]]);
      ans = i;
    }
  }
  cout << ans;
}
