#include <bits/stdc++.h>
using namespace std;
long long a[55], c, b[550000], d, n, m, dd, r, rr, x, e, l;
vector<long long> v;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> d;
    b[d] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (b[a[i]] == 1) v.push_back(a[i]);
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}
