#include <bits/stdc++.h>
using namespace std;
int const MOD = 1e9 + 7;
long long int bigmod(long long int a, long long int b) {
  if (b == 0) return 1 % MOD;
  long long int x = bigmod(a, b / 2);
  x = (x * x) % MOD;
  if (b % 2) x = (x * a) % MOD;
  return x;
}
int const N = 2e5 + 10;
vector<int> g[N];
long long int mask[50];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 2 and s[0] >= s[1]) {
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
      cout << "2" << '\n';
      cout << s[0] << " " << s.substr(1, s.size() - 1) << '\n';
    }
  }
  return 0;
}
