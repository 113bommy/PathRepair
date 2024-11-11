#include <bits/stdc++.h>
using namespace std;
const int maxn = 150007;
int n;
long long a[maxn];
map<long long, int> mp;
int len;
int main() {
  scanf("%d", &n);
  len = n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    while (mp[a[i]]) {
      len--;
      a[mp[a[i]]] = 0;
      mp[a[i]] = 0;
      a[i] *= 2;
    }
    mp[a[i]] = i;
  }
  printf("%d\n", len);
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) continue;
    printf("%d ", a[i]);
  }
}
