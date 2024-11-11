#include <bits/stdc++.h>
using namespace std;
const int maxn = 1510;
int n;
long long arr[maxn];
long long sum[maxn];
long long best = 0, ans = 0;
map<long long, vector<pair<int, int> > > m;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    sum[i] = sum[i - 1] + arr[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      long long temp = sum[j] - sum[i - 1];
      m[temp].push_back(make_pair(i, j));
    }
  }
  map<long long, vector<pair<int, int> > >::iterator sol;
  int last;
  for (map<long long, vector<pair<int, int> > >::iterator it = m.begin();
       it != m.end(); it++) {
    last = 0;
    best = 0;
    for (int j = 0; j < it->second.size(); j++) {
      if (j != 0 && it->second[j].first <= it->second[last].second) continue;
      best++;
      last = j;
    }
    if (best > ans) {
      ans = best;
      sol = it;
    }
  }
  last = 0;
  cout << ans << endl;
  for (int j = 0; j < sol->second.size(); j++) {
    if (j != 0 && sol->second[j].first <= sol->second[last].second) continue;
    last = j;
    cout << sol->second[j].first << " " << sol->second[j].second << endl;
  }
  return 0;
}
