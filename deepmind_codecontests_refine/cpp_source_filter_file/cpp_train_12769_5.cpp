#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
vector<pair<long long, long long>> point;
bool findans(long long s, long long d, long long n) {
  long long a = point[s].second - point[d].second;
  long long b = point[s].first - point[d].first;
  vector<bool> flag(n);
  for (long long i = 0; i < n; i++) {
    if ((b * (point[i].second - point[s].second)) ==
        (a * (point[i].first - point[s].first)))
      flag[i] = true;
  }
  vector<long long> t;
  long long flag1 = 0;
  for (long long i = 0; i < n; i++) {
    if (!flag[i]) {
      t.push_back(i);
      flag1++;
    }
  }
  if (flag1 <= 2) {
    return true;
  }
  a = point[t[0]].second - point[t[1]].second;
  b = point[t[0]].first - point[t[1]].first;
  for (long long i = 0; i < n; i++) {
    if ((b * (point[i].second - point[t[0]].second)) ==
        (a * (point[i].first - point[t[0]].second)))
      flag[i] = true;
  }
  bool ans = true;
  for (long long i = 0; i < n; i++) ans &= flag[i];
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    point.push_back(make_pair(x, y));
  }
  if (findans(0, 1, n) || findans(1, 2, n) || findans(0, 2, n) || n <= 4) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
