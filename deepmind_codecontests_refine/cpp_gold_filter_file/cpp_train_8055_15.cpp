#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const double pi = 3.14159265358979323846;
int n, m, k;
vector<int> a;
vector<int> b;
bool read() {
  if (!(cin >> n >> m >> k)) return false;
  a.resize(n);
  b.resize(m);
  for (int i = 0; i < int(n); ++i) cin >> a[i];
  for (int i = 0; i < int(m); ++i) cin >> b[i];
  return true;
}
void solve() {
  int l = 0;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < int(n); ++i) {
    while (l < m && a[i] > b[l]) l++;
    if (n - i > m - l) {
      cout << "YES";
      return;
    }
  }
  cout << "NO";
}
int main() {
  while (read()) solve();
  return 0;
}
