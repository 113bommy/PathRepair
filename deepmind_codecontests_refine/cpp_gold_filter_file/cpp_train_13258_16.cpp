#include <bits/stdc++.h>
using namespace std;
string solve(int f, vector<pair<int, int> >& xs) {
  int N = xs.size();
  sort(xs.begin(), xs.end());
  for (int i = 0; i < N; i++) {
    if (f > xs[i].first) {
      f += xs[i].second;
    } else {
      return "NO";
    }
  }
  return "YES";
}
int main() {
  int N, S;
  cin >> S >> N;
  vector<pair<int, int> > xs(N);
  for (int i = 0; i < N; i++) cin >> xs[i].first >> xs[i].second;
  auto ans = solve(S, xs);
  cout << ans << '\n';
  return 0;
}
