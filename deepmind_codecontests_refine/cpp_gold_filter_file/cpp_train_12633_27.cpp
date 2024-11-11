#include <bits/stdc++.h>
using namespace std;
double v[][2] = {{3.830127018922193, 3.366025403784439},
                 {-3.601321235851749, 10.057331467373021},
                 {0.466045194906253, 19.192786043799030},
                 {10.411264148588986, 18.147501411122495},
                 {12.490381056766580, 8.366025403784439}};
int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", n * 4 + 1);
  printf("%.15f %.15f\n", v[0][0], v[0][1]);
  for (int ni = 0; ni < n * 4; ni++) {
    printf("%.15f %.15f\n", v[ni % 4 + 1][0] + ni / 4 * (v[2][0] - v[0][0]),
           v[ni % 4 + 1][1] + ni / 4 * (v[2][1] - v[0][1]));
  }
  printf("%d %d %d %d %d\n", 1, 2, 3, 4, 5);
  for (int ni = 0; ni < n - 1; ni++) {
    printf("%d %d %d %d %d\n", 3 + ni * 4, 6 + ni * 4, 7 + ni * 4, 8 + ni * 4,
           9 + ni * 4);
  }
  printf("%d %d", 1, 3);
  for (int ni = 0; ni < n - 1; ni++) {
    printf(" %d", 7 + ni * 4);
  }
  for (int ni = n - 2; ni >= 0; ni--) {
    printf(" %d %d %d %d", 9 + ni * 4, 6 + ni * 4, 8 + ni * 4, 3 + ni * 4);
  }
  printf(" %d %d %d %d\n", 5, 2, 4, 1);
}
