#include <bits/stdc++.h>
int length[201000];
long long sol[101000];
int main() {
  int n;
  long long r;
  scanf("%d%I64d", &n, &r);
  r *= 2;
  sol[-1] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", length + i);
    length[i] *= 2;
  }
  long long left = 0;
  long long cur_t = 0;
  long long k = 0;
  bool possible = 1;
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    t *= 2;
    long long sub = std::min((long long)length[i], left);
    length[i] -= sub;
    left -= sub;
    t -= sub;
    if (t < length[i]) {
      possible = 0;
      break;
    }
    int to_cover = 2 * length[i] - t;
    int pots = 0;
    if (to_cover > 0)
      pots = (to_cover + r - 1) / r;
    else
      to_cover = 0;
    left += pots * r - to_cover;
    cur_t += (length[i] - to_cover) * 2;
    while (k < 100000 && pots > 0) {
      sol[k++] = cur_t / 2;
      cur_t += r;
      --pots;
    }
    k += pots;
  }
  if (possible) {
    printf("%I64d\n", k);
    if (k < 100000) {
      for (int i = 0; i < k; ++i) {
        printf("%I64d ", sol[i]);
      }
      printf("\n");
    }
  } else {
    printf("-1\n");
  }
  return 0;
}
