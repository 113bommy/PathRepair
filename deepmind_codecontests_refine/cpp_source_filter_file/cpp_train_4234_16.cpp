#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
template <class T>
inline T mod(T a, T b) {
  return (a % b + b) % b;
}
int m, n;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  if (m < n)
    puts("No");
  else
    puts("Yes");
  return 0;
}
