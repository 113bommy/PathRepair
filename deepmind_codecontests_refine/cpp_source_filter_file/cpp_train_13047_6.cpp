#include <bits/stdc++.h>
using namespace std;
int n, k, h;
long long m[100002];
long long v[100002];
vector<pair<long long, pair<long long, long long> > > vp;
vector<long long> ret;
vector<long long> working;
int ok(double m) {
  vector<long long> temp;
  int l = 1;
  for (int i = 0; i < n; i++) {
    if (vp[i].second.first * m > l * h * (1.0 - 1E-9)) {
      temp.push_back(vp[i].second.second);
      l++;
    }
    if (l == k + 1) {
      working = temp;
      return true;
    }
  }
  return false;
}
int main() {
  cout << setprecision(9);
  cin >> n >> k >> h;
  for (int i = 0; i < n; i++) cin >> m[i];
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) vp.push_back(make_pair(m[i], make_pair(v[i], i)));
  sort(vp.begin(), vp.end());
  double l = 0;
  double r = 1E9;
  for (int i = 0; i < 40; i++) {
    double m = (l + r) / 2;
    if (ok(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  for (int i = 0; i < k; i++) cout << 1 + working[i] << " ";
  cout << endl;
  return 0;
}
