#include <bits/stdc++.h>
using namespace std;
int main() {
  int v[2][3];
  scanf("%d %d %d %d %d %d", &v[0][0], &v[0][1], &v[0][2], &v[1][0], &v[1][1],
        &v[1][2]);
  int cnt = 0;
  for (int i = 0; i < 3; ++i) cnt += v[0][i] ^ v[1][i];
  if (cnt == 1)
    printf("YES");
  else
    printf("NO");
  return 0;
}
