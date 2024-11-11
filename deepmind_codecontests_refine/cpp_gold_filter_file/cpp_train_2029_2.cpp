#include <bits/stdc++.h>
using namespace std;
int a[100000], b[100000];
int main() {
  int aa = 0, bb = 0;
  char m[100005];
  scanf("%s", m);
  int k = strlen(m);
  for (int i = 0; i < k; i++) {
    if (m[i] == 'A') {
      if (m[i - 1] == 'B') b[bb++] = i;
      if (m[i + 1] == 'B') a[aa++] = i;
    }
  }
  if (aa * bb < 1) {
    printf("NO");
    return 0;
  }
  if (aa + bb > 3) {
    printf("YES");
    return 0;
  }
  sort(a, a + aa);
  sort(b, b + bb);
  if (b[bb - 1] - a[0] > 2) {
    printf("YES");
    return 0;
  }
  if (a[aa - 1] - b[0] > 0) {
    printf("YES");
    return 0;
  }
  printf("NO");
  return 0;
}
