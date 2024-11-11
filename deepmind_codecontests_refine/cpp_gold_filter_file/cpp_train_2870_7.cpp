#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979323;
const double EPS = 1e-12;
const int N = 1e6 + 5;
const int mod = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long a, b, mini = INT_MAX;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    mini = min(mini, b - a);
  }
  cout << mini + 1 << "\n";
  long long l = mini;
  long long l1 = 0;
  for (int i = 0; i < n; i++) {
    if (l1 <= l) {
      cout << l1 << " ";
      l1++;
    } else {
      l1 = 0;
      cout << l1 << " ";
      l1++;
    }
  }
}
