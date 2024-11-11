#include <bits/stdc++.h>
using namespace std;
int const MAXN = 200100;
int v[MAXN];
int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  if (b < n) return cout << -1, 0;
  vector<long long> v(n, 1);
  v[n - 1] = b - n + 1;
  long long sum = 0LL;
  for (int i = 0; i < n; i++) sum += v[i] * v[i];
  if (sum < a) return cout << -1, 0;
  for (int i = 0; i < n; i++) cout << v[i] << " ";
}
