#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = 1e6 + 7, mod = 1000000007, M = 2e9;
const long long MAX = 5e12;
int n, l, r;
vector<long long> a;
long long ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &l, &r);
    ans += r * n - l;
    a.push_back(l - r);
  }
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0; i < n; i++) ans += a[i] * (i + 1);
  cout << ans;
  return 0;
}
