#include <bits/stdc++.h>
using namespace std;
int s[102012];
int sum, W, N;
int id[102012];
inline bool cmp(int x, int y) { return s[x] < s[y]; }
int main() {
  scanf("%d%d", &N, &W);
  for (int i = 1; i <= N; ++i) scanf("%d", s + i), sum += s[i], id[i] = i;
  if (W <= 0) {
    puts("No");
  } else if (N == 1) {
    if (s[1] == W) {
      puts("Yes");
      for (int i = 1; i <= s[1]; ++i) printf("1 1 ");
    } else
      puts("No");
  } else {
    if (sum < W)
      puts("No");
    else {
      sort(id + 1, id + N + 1, cmp);
      sort(s + 1, s + N + 1);
      if (s[1] <= W) {
        puts("Yes");
        int Now = 1;
        while (Now <= N && W - s[Now] > 0) W -= s[Now], ++Now;
        printf("%d ", id[1]);
        for (int i = N; i >= Now + 1; --i)
          for (int j = 1; j <= s[i]; ++j) printf("%d %d ", id[i], id[i]);
        for (int i = s[Now] - W; i >= 1; --i)
          printf("%d %d ", id[Now], id[Now]);
        s[Now] = W;
        printf("%d ", id[1]);
        --s[1];
        for (int i = 1; i <= Now; ++i)
          for (int j = 1; j <= s[i]; ++j) printf("%d %d ", id[i], id[i]);
      } else {
        if (W == 1) {
          puts("No");
          return 0;
        }
        puts("Yes");
        --s[2];
        printf("%d ", id[2]);
        for (int i = s[1] - W + 1; i >= 1; --i) printf("%d %d ", 1, 1);
        printf("%d ", id[2]);
        printf("%d ", id[1]);
        for (int i = 2; i <= N; ++i)
          for (int j = 1; j <= s[i]; ++j) printf("%d %d ", id[i], id[i]);
        printf("%d ", id[1]);
        for (int i = 1; i < W - 1; ++i) printf("%d %d ", id[1], id[1]);
      }
    }
  }
  return 0;
}
