#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<long long int, long long int> > v;
  vector<pair<long long int, long long int> > vv;
  long long int n, k;
  cin >> n >> k;
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) {
    long long int l;
    cin >> l;
    sum += l;
    v.push_back(make_pair(l, i + 1));
  }
  long long int r = sum % n;
  if (r != 0) r = 1;
  sort(v.begin(), v.end());
  if (v[0].first + r == v[n - 1].first) {
    cout << r << " " << 0;
    return 0;
  }
  long long int u = 0;
  for (long long int i = 1; i <= k; i++) {
    vv.push_back(make_pair(v[n - 1].second, v[0].second));
    v[0].first++;
    v[n - 1].first--;
    sort(v.begin(), v.end());
    if (v[0].first + r == v[n - 1].first) {
      cout << r << " " << i << endl;
      u = 1;
      break;
    }
  }
  if (u == 1) {
    for (long long int i = 0; i < vv.size(); i++) {
      cout << vv[i].first << " " << vv[i].second << endl;
    }
    return 0;
  }
  cout << v[n - 1].first - v[0].first << " " << k << endl;
  for (long long int i = 0; i < vv.size(); i++)
    cout << vv[i].first << " " << vv[i].second << endl;
  return 0;
}
