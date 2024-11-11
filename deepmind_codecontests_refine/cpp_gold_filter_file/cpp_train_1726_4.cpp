#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int mod = 1000000007;
const double pi = acos(-1);
const long long OO = INT_MAX;
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int n, l;
  cin >> n >> l;
  int a[n], b[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int line[l + 1];
  memset(line, 0, sizeof(line));
  for (int x = 1; x <= l; x++) {
    for (int y = 1; y <= l; y++) {
      for (int i = 0; i < n; i++) {
        int temp = x + a[i];
        while (temp > l) temp -= l;
        line[temp] = 1;
      }
      for (int i = 0; i < n; i++) {
        int temp = y + b[i];
        while (temp > l) temp -= l;
        line[temp] = 1;
      }
      int c = 0;
      for (int i = 1; i <= l; i++) {
        c += line[i];
      }
      if (c == n) {
        return cout << "YES", 0;
      }
      memset(line, 0, sizeof(line));
    }
  }
  cout << "NO";
}
