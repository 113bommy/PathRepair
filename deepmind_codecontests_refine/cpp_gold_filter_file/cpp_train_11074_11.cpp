#include <bits/stdc++.h>
using namespace std;
int n, x = 1e9, y = 1e9, z, a[1000][1000], k, sol, sum, MOD = 10000007,
       b[1000005], m;
vector<int> v;
pair<int, int> p[1000000];
map<int, int> ma;
string s1, s2, s;
void getprime() {
  b[1] = 1;
  for (int i = 2; i <= 1000000; i++) {
    if (b[i]) continue;
    for (int q = 2 * i; q <= 1000000; q += i) {
      b[q] = 1;
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if (b[i] == 0) v.push_back(i);
  }
}
int main() {
  cin >> n >> m;
  getprime();
  for (int i = 0; i < n; i++)
    for (int q = 0; q < m; q++) cin >> a[i][q];
  for (int i = 0; i < n; i++) {
    for (int q = 0; q < m; q++) {
      if (b[a[i][q]] == 1) {
        auto it = lower_bound(v.begin(), v.end(), a[i][q]);
        z += *it - a[i][q];
      }
    }
    x = min(x, z);
    z = 0;
  }
  z = 0;
  for (int i = 0; i < m; i++) {
    for (int q = 0; q < n; q++) {
      if (b[a[q][i]] == 1) {
        auto it = lower_bound(v.begin(), v.end(), a[q][i]);
        z += *it - a[q][i];
      }
    }
    y = min(z, y);
    z = 0;
  }
  cout << min(x, y) << endl;
  return 0;
}
