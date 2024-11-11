#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const long long mod = 1e9 + 7;
const int INF = 1e9;
const double eps = 1e-6;
int n;
int a[maxn];
map<long long, int> mp;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    while (mp.find(a[i]) != mp.end()) {
      a[mp[a[i]]] = 0;
      mp.erase(a[i]);
      a[i] *= 2;
    }
    mp[a[i]] = i;
  }
  printf("%d\n", mp.size());
  for (int i = 1; i <= n; i++) {
    if (a[i]) printf("%lld ", a[i]);
  }
  puts("");
}
