#include <bits/stdc++.h>
using namespace std;
bool a[100005];
int n = 100000;
void seieve() {
  a[0] = a[1] = true;
  for (int i = 4; i <= n; i += 2) {
    a[i] = true;
  }
  int x = sqrt(n);
  for (int i = 3; i <= x; i += 2) {
    if (!a[i]) {
      for (int j = i * i; j <= n; j += 2 * i) {
        a[j] = true;
      }
    }
  }
}
int ma[505][505];
vector<int> v;
int g(int val) {
  if (!a[val]) return val;
  int x = *(upper_bound(v.begin(), v.end(), val));
  return x;
}
int main() {
  seieve();
  for (int i = 2; i <= n; i++) {
    if (!a[i]) {
      v.push_back(i);
    }
  }
  int ni, m;
  cin >> ni >> m;
  for (int i = 0; i < ni; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ma[i][j];
      ma[i][j] = g(ma[i][j]) - ma[i][j];
      if (ma[i][j] < 0) {
        cout << "Hello";
      }
    }
  }
  int64_t mi = INT_MAX;
  for (int i = 0; i < ni; i++) {
    int64_t s = 0;
    for (int j = 0; j < m; j++) {
      s += ma[i][j];
    }
    mi = min(mi, s);
  }
  for (int i = 0; i < m; i++) {
    int64_t s = 0;
    for (int j = 0; j < ni; j++) {
      s += ma[j][i];
    }
    mi = min(mi, s);
  }
  cout << mi;
  return 0;
}
