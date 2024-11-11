#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long lnf = 0x3f3f3f3f3f3f3f3f;
const double dnf = 1e18;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxm = 100100;
const int up = 100000;
const int hashp = 13331;
const int maxn = 3100;
long long fac[maxn], inv[maxn];
long long n, p;
int a[maxn << 1], sum[maxn << 1];
vector<int> vc;
int main(void) {
  scanf("%lld%lld", &n, &p);
  for (int i = 1; i <= (n); i++) scanf("%d", &a[i]), sum[a[i]]++;
  for (int i = 1; i < (maxn << 1); i++) sum[i] += sum[i - 1];
  for (int x = 1; x < maxn; x++) {
    long long ans = 1;
    for (int i = x; i < x + n; i++) {
      ans =
          ans * (((0ll) > (sum[i] - (i - x)) ? (0ll) : (sum[i] - (i - x)))) % p;
    }
    if (ans) vc.push_back(x);
  }
  cout << vc.size() << endl;
  for (int i = 0; i < vc.size(); i++) printf("%d ", vc[i]);
  cout << endl;
  return 0;
}
