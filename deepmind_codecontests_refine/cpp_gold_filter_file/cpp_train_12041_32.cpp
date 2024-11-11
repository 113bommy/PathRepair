#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e18 + 9;
const long long MOD = 1e9 + 7;
long long t, n, m, k;
long long a[100005], c[100005];
string s[100005];
map<string, long long> p;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  if (n <= 5)
    cout << -1 << '\n';
  else {
    cout << "1 2\n1 3\n1 4\n";
    for (int i = 5; i <= n; i++) cout << 2 << ' ' << i << '\n';
  }
  for (int i = 1; i < n; i++) cout << 1 << ' ' << i + 1 << '\n';
}
