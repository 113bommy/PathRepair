#include <bits/stdc++.h>
using namespace std;
const int N = (int)(2e5 + 5);
int n, a, b;
vector<pair<long long, long long> > game;
bool comp(const pair<long long, long long> &a,
          const pair<long long, long long> &b) {
  return a.first - a.second > b.first - b.second;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  scanf("%d %d %d", &n, &a, &b);
  game.resize(n);
  for (int i = 0; i < n; i++) scanf("%d %d", &game[i].first, &game[i].second);
  sort(game.begin(), game.end(), comp);
  b = min(b, n);
  long long sum = 0;
  for (int i = 0; i < n; i++)
    sum += max(game[i].second, i < b ? game[i].first : 0);
  long long mindiff =
      b > 0 ? max(game[b - 1].first - game[b - 1].second, 0LL) : 0;
  long long ans = sum;
  if (a > 0) {
    for (int i = 0; i < n; i++) {
      long long newdiff = max((game[i].first << a) - game[i].second, 0LL);
      long long olddiff =
          i < b ? max(game[i].first - game[i].second, 0LL) : mindiff;
      if (newdiff > mindiff) ans = max(ans, sum + newdiff - olddiff);
    }
  }
  cout << ans << endl;
  return 0;
}
