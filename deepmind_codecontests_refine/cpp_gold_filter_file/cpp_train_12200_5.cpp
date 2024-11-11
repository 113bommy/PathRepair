#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const long long mod = 1e9 + 7;
long long a[1005][1005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  }
  vector<int> V;
  long long now = a[2][1] * a[3][1] / a[3][2];
  now = sqrt(now);
  V.push_back(now);
  for (int i = 2; i <= n; i++) {
    V.push_back(a[i][1] / V[0]);
  }
  for (auto &x : V) {
    cout << x << ' ';
  }
  cout << '\n';
}
