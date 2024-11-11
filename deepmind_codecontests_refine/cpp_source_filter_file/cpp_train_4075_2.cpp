#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e9;
const int maxn = 2e5 + 10;
const int maxq = 1e3 + 10;
const int alf = 26;
const int dlm = 1e9 + 7;
const long long mod = 998244353;
string O[] = {"YES", "NO", "Yes", "No"};
int d[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  sort(d, d + n);
  int x = d[n - 1];
  int y;
  int o = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (x % d[i] != 0) {
      y = d[i];
      break;
    }
    if (o == d[i]) {
      y = d[i];
      break;
    }
    o = d[i];
  }
  cout << x << " " << y;
}
