#include <bits/stdc++.h>
using namespace std;
pair<int, int> pt[2000];
int n;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
pair<int, int> operator-(pair<int, int> l, pair<int, int> r) {
  return make_pair(l.first - r.first, l.second - r.second);
}
int operator*(pair<int, int> l, pair<int, int> r) {
  return l.first * r.first + l.second * r.second;
}
pair<int, int> normalize(pair<int, int> val) {
  pair<int, int> ret = make_pair(val.second, -val.first);
  int d = max(gcd(abs(ret.first), abs(ret.second)), 1);
  ret.first /= d;
  ret.second /= d;
  if (ret.second < 0 || (ret.second == 0 && ret.first < 0))
    ret = make_pair(0, 0) - ret;
  return ret;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> pt[i].first >> pt[i].second;
  long long result = n * (n - 1) * (n - 2) / 2 / 3;
  long long sub = 0;
  for (int i = 0; i < n; i++) {
    vector<pair<int, int> > dir;
    for (int j = 0; j < n; j++) {
      dir.push_back(normalize(pt[j] - pt[i]));
    }
    sort(dir.begin(), dir.end());
    for (int second = 0, e = 0; e < dir.size(); second = e) {
      while (e < dir.size() && dir[e] == dir[second]) e++;
      sub += (e - second) * (e - second - 1) / 2;
    }
  }
  cout << result - sub / 3 << '\n';
  return 0;
}
