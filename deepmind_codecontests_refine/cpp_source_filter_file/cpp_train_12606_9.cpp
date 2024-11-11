#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int> > v;
vector<long long int> v2;
set<char> st;
map<string, int> mp;
long long int a[100005];
int main() {
  long long int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  long long int sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i].second;
  }
  if (sum > m)
    cout << -1 << endl;
  else {
    for (int i = 0; i < v.size(); i++) {
      v2.push_back(v[i].first - v[i].second);
    }
    long long int cnt = 0;
    sort(v2.begin(), v2.end());
    for (int i = 0; i < v2.size(); i++) {
      if (sum + v2[i] <= m) {
        cnt++;
        sum += v2[i];
      } else
        break;
    }
    cout << cnt << endl;
  }
  return 0;
}
