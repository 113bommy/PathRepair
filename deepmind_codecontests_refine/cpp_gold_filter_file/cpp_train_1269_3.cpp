#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<unsigned int> fib(max(n, m) + 5, 0);
  fib[1] = 1;
  fib[2] = 2;
  const int mod = 1e9 + 7;
  for (int i = 3; i < fib.size(); i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
  cout << ((unsigned)2) * (fib[n] + fib[m] - (unsigned)1) % mod << '\n';
}
