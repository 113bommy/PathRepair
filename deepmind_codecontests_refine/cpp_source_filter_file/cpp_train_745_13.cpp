#include <bits/stdc++.h>
using namespace std;
bool islucky(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return false;
    x /= 10;
  }
  return true;
}
int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  vector<long long> u;
  for (int(i) = 0; (i) < (int)(11); ++(i))
    if (i)
      for (int(mask) = 0; (mask) < (int)(1 << i); ++(mask)) {
        long long p = 0;
        for (int(j) = 0; (j) < (int)(i); ++(j)) {
          if (mask >> j & 1)
            p = p * 10 + 7;
          else
            p = p * 10 + 4;
        }
        u.push_back(p);
      }
  int len = 0;
  long long s = 1;
  while (s < K) s *= ++len;
  if (N < len) return puts("-1");
  vector<int> v;
  for (int(i) = 0; (i) < (int)(len); ++(i)) v.push_back(N - len + 1 + i);
  int ans = 0;
  for (int(i) = 0; (i) < (int)(len); ++(i)) {
    s /= len - i;
    int x = (K - 1) / s;
    if (islucky(N - len + 1 + i) && islucky(v[x])) ans++;
    v.erase(v.begin() + x);
    K -= x * s;
  }
  for (int(i) = 0; (i) < (int)(u.size()); ++(i))
    if (u[i] < (N - len)) ans++;
  printf("%d\n", ans);
}
