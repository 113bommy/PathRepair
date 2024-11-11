#include <bits/stdc++.h>
using namespace std;
double const EPS = 1e-8, PI = acos(-1);
const int N = 1e9 + 9, M = 1e6 + 1, OO = 1e9 + 1;
const long long MOD = 1e9 + 7;
void INPUT() {
  cout << fixed << setprecision(0);
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
int n, m, a, b;
int main() {
  INPUT();
  cin >> n >> m >> a >> b;
  int arr1[n], arr2[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr1[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> arr2[i];
  }
  bool can = (arr1[a - 1] < arr2[m - b]);
  cout << (can ? "YES\n" : "NO\n");
  return 0;
}
