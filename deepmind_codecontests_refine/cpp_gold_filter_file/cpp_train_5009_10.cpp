#include <bits/stdc++.h>
using namespace std;
map<long long, vector<pair<long long, long long> > > ar;
long long DP[200005][2];
long long N;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first < b.first) {
    return (true);
  } else if (a.first == b.first) {
    return (a.second >= b.second);
  }
  return (false);
}
long long dist(pair<long long, long long> a, pair<long long, long long> b) {
  return (abs(a.first - b.first) + abs(a.second - b.second));
}
int main() {
  cin >> N;
  long long max_val = 0;
  for (long long i = 0; i < N; i++) {
    long long a, b;
    cin >> a >> b;
    ar[max(a, b)].push_back(pair<long long, long long>(a, b));
    max_val = max(max_val, max(a, b));
  }
  ar[0].push_back(pair<long long, long long>(0, 0));
  for (map<long long, vector<pair<long long, long long> > >::iterator it =
           ar.begin();
       it != ar.end(); it++) {
    sort(ar[it->first].begin(), ar[it->first].end(), cmp);
  }
  long long i = 0;
  for (map<long long, vector<pair<long long, long long> > >::iterator it =
           ar.begin();
       it != ar.end(); it++) {
    if (it->first == max_val) break;
    pair<long long, long long> f_left = ar[it->first][0];
    pair<long long, long long> f_right = ar[it->first].back();
    it++;
    pair<long long, long long> n_left = ar[it->first][0];
    pair<long long, long long> n_right = ar[it->first].back();
    it--;
    DP[i + 1][0] =
        min(DP[i][0] + dist(f_left, n_left), DP[i][1] + dist(f_right, n_left));
    DP[i + 1][1] = min(DP[i][0] + dist(f_left, n_right),
                       DP[i][1] + dist(f_right, n_right));
    DP[i + 1][0] += dist(n_left, n_right);
    DP[i + 1][1] += dist(n_left, n_right);
    long long tmp = DP[i + 1][0];
    DP[i + 1][0] = DP[i + 1][1];
    DP[i + 1][1] = tmp;
    i++;
  }
  cout << min(DP[i][0], DP[i][1]) << endl;
  return (0);
}
