#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long l = 1900, h = 1899;
  vector<pair<long long, long long> > v;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    pair<long long, long long> p = make_pair(a, b);
    v.push_back(p);
  }
  long long sum = 0, lt = l, ht = h, flag = 0, flag1 = 0;
  for (long long i = n - 1; i >= 0; i--) {
    sum += v[i].first;
    lt = 1900;
    ht = 1899;
    if (v[i].second == 2) {
      ht = ht + sum;
      if (ht < h || flag == 0) {
        h = ht;
        flag = 1;
      }
    } else {
      lt = lt + sum;
      if (lt > l || flag1 == 0) {
        l = lt;
        flag1 = 1;
      }
    }
  }
  if (flag == 0)
    cout << "Infinity" << endl;
  else if (l > h && flag1 != 0)
    cout << "Impossible" << endl;
  else
    cout << h << endl;
}
