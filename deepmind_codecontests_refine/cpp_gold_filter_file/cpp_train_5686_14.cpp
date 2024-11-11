#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, l, r, e = 1000000001;
  cin >> n;
  vector<long long> a;
  vector<long long> b;
  vector<long long> c;
  vector<long long> d;
  vector<long long>::iterator it;
  b.push_back(-1);
  c.push_back(-1);
  d.push_back(-1);
  for (long long i = 0; i < n; i++) {
    cin >> l >> r;
    a.push_back(l * e + r);
  }
  sort(a.begin(), a.end());
  for (long long i = 0; i < n; i++) {
    if (a[i] / e > b[b.size() - 1]) {
      b.push_back(a[i] / e);
      b.push_back(a[i] % e);
    } else if (a[i] / e > c[c.size() - 1]) {
      c.push_back(a[i] / e);
      c.push_back(a[i] % e);
    } else {
      d.push_back(a[i] / e);
      d.push_back(a[i] % e);
    }
  }
  ((b.size() + c.size() - 2) / 2 == a.size()) ? cout << "YES" : cout << "NO";
}
