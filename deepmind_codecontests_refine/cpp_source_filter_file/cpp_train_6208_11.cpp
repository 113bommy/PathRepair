#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int p[6];
int sum;
bool result;
int main() {
  for (int i = 0; i < (6); ++i) {
    scanf("%d", &p[i]);
    sum += p[i];
  }
  for (int i = 0; i < (6); ++i) {
    for (int j = (i + 1); j <= (6); ++j) {
      for (int k = (j + 1); k <= (6); ++k) {
        int tmp_sum = p[i] + p[j] + p[k];
        if (tmp_sum * 2 == sum) {
          printf("YES");
          return 0;
        }
      }
    }
  }
  printf("NO");
  return 0;
}
