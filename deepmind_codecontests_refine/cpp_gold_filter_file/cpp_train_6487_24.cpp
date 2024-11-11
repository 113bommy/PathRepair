#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const long long int int_max = 1e18;
using namespace std;
vector<long long int> parent;
void file_i_o() {
  ios::sync_with_stdio(false), cin.tie(0);
  cout.tie(0);
}
long long int fast_pow(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b % 2) ans = (ans) % mod * (a % mod), b--;
    a = (a * a) % mod;
    b = (b >> 1) % mod;
  }
  return ans % mod;
}
long long int counts = 0;
long long int get(long long int a) {
  return (a == parent[a] ? a : parent[a] = get(parent[a]));
}
void unions(long long int x, long long int y) {
  x = get(x);
  y = get(y);
  if (x == y) return;
  parent[y] = x;
  counts++;
}
int main(int argc, char const *argv[]) {
  file_i_o();
  long long int n, m, k;
  cin >> n >> m >> k;
  parent.resize(n + 1);
  for (long long int i = 0; i <= n; i++) parent[i] = i;
  for (long long int i = 1; i <= n; i++) {
    long long int j = 0;
    while (j < k / 2 and i + k - 1 - j <= n) {
      unions(i + j, i + k - 1 - j);
      j++;
    }
  }
  cout << fast_pow(m, n - counts) << endl;
  return 0;
}
