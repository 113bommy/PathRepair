#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = LONG_MAX;
const long long inf64 = LLONG_MAX;
const long double pi = 3.1415926535897932384626433832795;
int k, x, n, m;
struct st {
  long long j12, g12, jg21, g21, gj21, ak;
};
int ans1[1000], ans2[1000];
int main() {
  scanf("%d%d%d%d", &k, &x, &n, &m);
  for (int j1 = 0; j1 < 3; j1++)
    for (int j2 = 0; j2 < 3; j2++)
      for (int g1 = 0; g1 < 3; g1++)
        for (int g2 = 0; g2 < 3; g2++)
          for (int k1 = 0; k1 <= n / 2; k1++)
            for (int k2 = 0; k2 <= m / 2; k2++) {
              st f, s;
              f.j12 = 1;
              f.g12 = 0, f.jg21 = 0, f.g21 = 0, f.gj21 = 0, f.ak = k1;
              s.j12 = 0;
              s.g12 = 1, s.jg21 = 0, s.g21 = 0, s.gj21 = 0, s.ak = k2;
              for (int i = 3; i <= k; i++) {
                st z = f;
                f = s;
                s.j12 += z.j12;
                s.g12 += z.g12;
                s.jg21 += z.jg21;
                s.g21 += z.g21;
                s.gj21 += z.gj21;
                s.ak += z.ak;
                if (i == 3) s.jg21++;
                if (i > 3) {
                  if (i % 2 == 0)
                    s.gj21++;
                  else
                    s.g21++;
                }
                if (s.ak > x) break;
              }
              long long rez = s.ak;
              if (j1 == 0 && j2 == 1 && n == 2) rez += s.j12;
              if (g1 == 0 && g2 == 1 && m == 2) rez += s.g12;
              if (j2 == 0 && g1 == 1) rez += s.jg21;
              if (g2 == 0 && g1 == 1) rez += s.g21;
              if (g2 == 0 && j1 == 1) rez += s.gj21;
              if (rez == x) {
                for (int i = 0; i < n; i++) ans1[i] = 2;
                for (int i = 0; i < m; i++) ans2[i] = 2;
                ans1[0] = j1, ans1[n - 1] = j2;
                ans2[0] = g1, ans2[m - 1] = g2;
                if (n == 1 && j1 != j2) break;
                if (m == 1 && g1 != g2) break;
                int kk = k1, last = 1;
                if (n <= 2 && kk != 0) break;
                if (j1 == 0 && kk) ans1[1] = 1, kk--, last++;
                for (int i = 0; i < kk; i++)
                  if ((last == n - 1 && j2 != 0) ||
                      (last + 1 == n - 1 && j2 != 1) || last + 1 >= n)
                    goto lol;
                  else
                    ans1[last] = 0, ans1[last + 1] = 1, last += 2;
                kk = k2, last = 1;
                if (m <= 2 && kk != 0) break;
                if (g1 == 0 && kk) ans2[1] = 1, kk--, last++;
                for (int i = 0; i < kk; i++)
                  if ((last == m - 1 && g2 != 0) ||
                      (last + 1 == m - 1 && g2 != 1) || last + 1 >= m)
                    goto lol;
                  else
                    ans2[last] = 0, ans2[last + 1] = 1, last += 2;
                for (int i = 0; i < n; i++) switch (ans1[i]) {
                    case 0:
                      printf("A");
                      break;
                    case 1:
                      printf("C");
                      break;
                    case 2:
                      printf("X");
                  }
                printf("\n");
                for (int i = 0; i < m; i++) switch (ans2[i]) {
                    case 0:
                      printf("A");
                      break;
                    case 1:
                      printf("C");
                      break;
                    case 2:
                      printf("X");
                  }
                return 0;
              lol:
                int end = 0;
              }
            }
  printf("Happy new year!");
  return 0;
}
