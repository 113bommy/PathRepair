#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, rs = 0, x;
  vector<long long> a;
  cin >> n >> k;
  for (long i = 1; i <= n; i++) cin >> x, a.push_back(x);
  sort((a).begin(), (a).end());
  for (long i = 1; i <= k; i++) rs += a[i];
  cout << rs;
}
