#include <bits/stdc++.h>
int main(int argc, char const* argv[]) {
  double pi = asin(1) * 2.0;
  int n = ({
    int t;
    scanf("%d", &t);
    t;
  }),
      R = ({
        int t;
        scanf("%d", &t);
        t;
      }),
      r = ({
        int t;
        scanf("%d", &t);
        t;
      });
  if (n == 1) {
    printf("%s\n", R >= r ? "YES" : "NO");
    return 0;
  }
  int sr = R - r;
  double tr = sr * cos((pi - 2 * pi / n) / 2);
  if (tr >= (double)r)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
