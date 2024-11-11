#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, long long> m;
void rec(vector<int> &a, int i) {
  if (a.size() <= 1) return;
  if (i < 0) return;
  vector<int> o, z;
  long long inv = 0;
  int n1 = 0, n0 = 0;
  long long temp = (1 << i);
  int n = a.size();
  for (int j = 0; j < n; j++) {
    if (a[j] & temp) {
      o.push_back(a[j]);
      n1++;
    } else {
      z.push_back(a[j]);
      inv += n1;
    }
  }
  m[{i, 0}] += inv;
  inv = 0;
  for (int j = 0; j < n; j++) {
    if (a[j] & temp)
      inv += n0;
    else
      n0++;
  }
  m[{i, 1}] += inv;
  rec(o, i - 1);
  rec(z, i - 1);
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  int x = 0;
  int msb = log2(mx);
  long long inv = 0;
  rec(a, msb);
  for (int i = 0; i <= msb; i++) {
    if (m[{i, 0}] > m[{i, 1}]) x += pow(2, i);
    inv += min(m[{i, 0}], m[{i, 1}]);
  }
  cout << inv << " " << x << endl;
}
