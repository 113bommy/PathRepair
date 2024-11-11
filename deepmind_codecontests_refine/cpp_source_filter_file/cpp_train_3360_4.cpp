#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5, inf = 1e18;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, x;
    cin >> n >> x;
    long long int ary[n];
    long long int sum = 0;
    long long int f = 0;
    for (long long int i = 0; i < n; ++i) {
      cin >> ary[i];
      sum += ary[i];
      if (ary[i] != x) f++;
    }
    if (!f)
      cout << f << "\n";
    else if (sum == x * n || f == n)
      cout << 1 << "\n";
    else
      cout << 2 << "\n";
  }
  return 0;
}
