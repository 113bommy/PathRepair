#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  map<long long, int> Servers;
  Servers[0] = k;
  for (int i = 0; i < n; i++) {
    int s, m;
    scanf("%d%d", &s, &m);
    map<long long, int>::iterator it = Servers.begin();
    long long begin = max(it->first, 1ll * s);
    long long ans = begin + m;
    printf("%d\n", ans);
    Servers[ans]++;
    it->second--;
    if (it->second == 0) Servers.erase(it);
  }
  return 0;
}
