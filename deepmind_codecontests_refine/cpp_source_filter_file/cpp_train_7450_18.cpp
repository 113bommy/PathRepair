#include <bits/stdc++.h>
using namespace std;
const long long int INF = 9223372036854775807;
const long long int mod = 998244353;
vector<long long int> v;
long long int first(int n, long long int k) {
  if (n == 1) return 1;
  if (k == v[n] / 2 + 1)
    return n;
  else {
    if (k < v[n] / 2 + 1)
      return first(n - 1, k);
    else
      return first(n - 1, k - v[n] / 2 + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  long long int k;
  cin >> n >> k;
  v.resize(n + 1);
  v[1] = 1;
  for (int i = 2; i <= n; i++) {
    v[i] = 2 * v[i - 1] + 1;
  }
  cout << first(n, k);
}
