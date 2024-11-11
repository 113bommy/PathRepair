#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, a, nc = 0, pc = 0, j = 0, k = 0, count = 0;
  cin >> n;
  vector<pair<long long, long long> > ne;
  vector<pair<long long, long long> > po;
  for (int i = 0; i < n; i++) {
    cin >> x >> a;
    if (x < 0) {
      ne.push_back(make_pair(-1 * x, a));
      nc++;
    } else {
      po.push_back(make_pair(x, a));
      pc++;
    }
  }
  sort(ne.begin(), ne.end());
  sort(po.begin(), po.end());
  if (nc > pc) {
    for (int i = 0; i < po.size(); i++) {
      count += po[i].second;
    }
    for (int i = 0; i < po.size() + 1; i++) {
      count += ne[i].second;
    }
  } else if (pc > nc) {
    for (int i = 0; i < ne.size(); i++) {
      count += ne[i].second;
    }
    for (int i = 0; i < ne.size() + 1; i++) {
      count += po[i].second;
    }
  } else {
    for (int i = 0; i < ne.size(); i++) {
      count += ne[i].second;
    }
    for (int i = 0; i < po.size(); i++) {
      count += po[i].second;
    }
  }
  cout << count;
  return 0;
}
