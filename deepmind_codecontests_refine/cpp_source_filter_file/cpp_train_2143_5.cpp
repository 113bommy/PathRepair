#include <bits/stdc++.h>
using namespace std;
vector<int> v(10001);
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0, a; i < n; i++) scanf("%d", &a), v[a]++;
  long long cnt = 0;
  if (k > 0)
    for (int i = 0; i <= 10000; i++)
      for (int j = i + 1; j <= 10000; j++) {
        if (v[i] != 0 && v[j] != 0) {
          int t = i ^ j;
          int c = 0;
          while (t != 0) c += t & 1, t >>= 1;
          if (c == k) cnt += v[i] * v[j];
        }
      }
  else {
    for (int i = 0; i <= 10000; i++) cnt += v[i] * (v[i] - 1) / 2;
  }
  printf("%I64d\n", cnt);
  return 0;
}
