#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int> > v(n);
  long long int fq = 0, sq = 0, tq = 0, ft = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    if (v[i].first > 0 && v[i].second > 0)
      fq++;
    else if (v[i].first < 0 && v[i].second > 0)
      sq++;
    else if (v[i].first < 0 && v[i].second < 0)
      tq++;
    else
      ft++;
  }
  if ((sq + tq >= n - 1) || (ft + fq >= n - 1))
    cout << "Yes\n";
  else
    cout << "No\n";
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
