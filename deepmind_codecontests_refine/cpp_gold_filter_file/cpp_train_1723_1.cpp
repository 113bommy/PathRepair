#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
int n;
long long cnt[N];
long long pairs[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    cnt[x] += 1;
  }
  for (int a = 1; a < N; a++) {
    if (!cnt[a]) continue;
    for (int b = a; b < N; b += a) {
      if (a * a == b)
        pairs[b] += cnt[a] * (cnt[a] - 1);
      else
        pairs[b] += cnt[a] * cnt[b / a];
    }
  }
  for (int i = 1; i < N; i++) pairs[i] += pairs[i - 1];
  int q;
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", 1LL * n * (n - 1) - pairs[x - 1]);
  }
}
