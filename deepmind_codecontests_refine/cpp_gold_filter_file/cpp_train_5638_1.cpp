#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int aa[3 * 100005][2];
vector<pair<pair<long long int, long long int>, long long int> > v1, v2;
long long int cmp1(pair<pair<long long int, long long int>, long long int> a,
                   pair<pair<long long int, long long int>, long long int> b) {
  if (a.first.first < b.first.second) {
    return 0;
  }
  return 1;
}
long long int cmp2(pair<pair<long long int, long long int>, long long int> a,
                   pair<pair<long long int, long long int>, long long int> b) {
  if (a.first.first > b.first.second) {
    return 0;
  }
  return 1;
}
void solve() {
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> aa[i][0] >> aa[i][1];
    if (aa[i][0] < aa[i][1])
      v1.push_back(make_pair(make_pair(aa[i][0], aa[i][1]), i + 1));
    else
      v2.push_back(make_pair(make_pair(aa[i][0], aa[i][1]), i + 1));
  }
  sort((v1).begin(), (v1).end(), cmp1);
  sort((v2).begin(), (v2).end(), cmp2);
  if (v1.size() > v2.size()) {
    cout << v1.size() << endl;
    for (long long int i = 0; i < v1.size(); i++) {
      cout << v1[i].second << " ";
    }
  } else {
    cout << v2.size() << endl;
    for (long long int i = 0; i < v2.size(); i++) {
      cout << v2[i].second << " ";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t = 1;
  for (long long int tc = 1; tc <= t; tc++) {
    solve();
  }
}
