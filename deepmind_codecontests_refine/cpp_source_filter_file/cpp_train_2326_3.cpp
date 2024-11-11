#include <bits/stdc++.h>
const long long inf = 1e9 + 44;
const int MAX = 3e5 + 9;
const long long MOD = 1e9 + 7;
const double eps = 1e-10;
double const PI = 3.1415926535897931;
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void _print(vector<int> v) {
  cout << "[ ";
  for (auto u : v) cout << u << " ";
  cout << " ]" << endl;
}
int main() {
  int n, d;
  cin >> d;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int ans = 0;
  for (int i = 1; i < n; i++) ans = ans + d - v[i];
  cout << ans;
}
