#include <bits/stdc++.h>
using namespace std;
int n, k;
long long p;
int a[300005];
int main() {
  cin >> n >> p >> k;
  unordered_map<long long, long long> prs;
  prs.clear();
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    long long num = a[i] * a[i] % p;
    num = num * a[i] % p;
    num = num * a[i] % p;
    num = (num - k * a[i] % p + p) % p;
    prs[num]++;
  }
  long long ans = 0LL;
  for (auto pr : prs) {
    long long num = pr.second;
    ans += num * (num - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
