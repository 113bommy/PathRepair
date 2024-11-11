#include <bits/stdc++.h>
using namespace std;
int Set(int n, int pos) { return n = n | (1 << pos); }
int reset(int n, int pos) { return n = n & ~(1 << pos); }
bool check(int n, int pos) { return (bool)(n & (1 << pos)); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  m--;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int z = min_element(a, a + n) - a;
  vector<int> mn;
  for (int i = z + 1; i <= m; i++) {
    if (a[z] == a[i]) mn.push_back(i);
  }
  for (int i = 0; i < mn.size(); i++) {
    if (mn[i] <= m) {
      if (i + 1 == (int)mn.size() or mn[i + 1] > m) {
        z = mn[i];
        break;
      }
    } else {
      if (mn[0] > m and i + 1 == (int)mn.size()) {
        z = mn[i];
        break;
      }
    }
  }
  if (m < z) {
    long long x = 0, y = a[z];
    for (int i = 0; i < n; i++) {
      if (i <= m or i > z)
        x += y + 1, a[i] -= y + 1;
      else
        x += y, a[i] -= y;
    }
    a[z] += x;
  } else {
    long long x = 0, y = a[z];
    for (int i = 0; i < n; i++) {
      if (i <= z or i > m)
        x += y, a[i] -= y;
      else
        x += y + 1, a[i] -= y + 1;
    }
    a[z] += x;
  }
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  return 0;
}
