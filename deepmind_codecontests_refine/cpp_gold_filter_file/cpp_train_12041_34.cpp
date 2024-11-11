#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
const int N = 1e6 + 100;
const long long int INF = 1e18;
const long long int mod = 1e9 + 7;
const long long int hashh = 311;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n < 6)
    cout << -1 << "\n";
  else {
    if (n % 2 == 0) {
      for (int i = 1; i <= n - 6; i++) cout << i << " " << i + 1 << "\n";
      cout << n - 5 << " " << n - 4 << "\n";
      cout << n - 5 << " " << n - 3 << "\n";
      cout << n - 5 << " " << n - 2 << "\n";
      cout << n - 3 << " " << n - 1 << "\n";
      cout << n - 3 << " " << n << "\n";
    } else {
      for (int i = 1; i <= n - 7; i++) cout << i << " " << i + 1 << "\n";
      cout << n - 6 << " " << n - 5 << "\n";
      cout << n - 6 << " " << n - 4 << "\n";
      cout << n - 6 << " " << n - 3 << "\n";
      cout << n - 6 << " " << n - 2 << "\n";
      cout << n - 3 << " " << n - 1 << "\n";
      cout << n - 3 << " " << n << "\n";
    }
  }
  for (int i = 1; i < n; i++) cout << i << " " << i + 1 << "\n";
}
