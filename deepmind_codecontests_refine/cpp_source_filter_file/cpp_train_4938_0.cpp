#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
struct node {
  int id, w;
} w1[100010], w2[100010];
bool cmp(node a, node b) { return a.w > b.w; }
long long s1[100010], s2[100010];
int main() {
  int n, v;
  scanf("%d%d", &n, &v);
  memset(s1, 0, sizeof(s1));
  memset(s2, 0, sizeof(s2));
  int num1 = 0, num2 = 0;
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 1) {
      w1[++num1].w = b;
      w1[num1].id = i;
    } else {
      w2[++num2].w = b;
      w2[num2].id = i;
    }
  }
  sort(w1 + 1, w1 + 1 + num1, cmp);
  sort(w2 + 1, w2 + 1 + num2, cmp);
  for (int i = 1; i <= num1; i++) s1[i] = s1[i - 1] + w1[i].w;
  for (int i = 1; i <= num2; i++) s2[i] = s2[i - 1] + w2[i].w;
  int temp1 = 0, temp2 = 0;
  int mmax = 0;
  for (int i = 1; i * 2 <= v && i <= num2; i++) {
    int cnt = v - 2 * i;
    if (cnt > num1) cnt = num1;
    if (s2[i] + s1[cnt] > mmax) {
      temp1 = cnt;
      temp2 = i;
      mmax = s2[i] + s1[cnt];
    }
  }
  printf("%d\n", mmax);
  for (int i = 1; i <= temp1; i++) {
    if (i == 1)
      printf("%d", w1[i].id);
    else
      printf(" %d", w1[i].id);
  }
  for (int i = 1; i <= temp2; i++) {
    if (i == 1 && temp1 == 0)
      printf("%d", w2[i].id);
    else
      printf(" %d", w2[i].id);
  }
  printf("\n");
  return 0;
}
