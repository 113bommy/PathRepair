#include <bits/stdc++.h>
using namespace std;
bool a[100005];
char c[100005];
int p[100005];
int li[100005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  getchar();
  int co = 0;
  int last;
  for (int i = 0; i < m; i++) {
    scanf("%c %d", &c[i], &p[i]);
    getchar();
    char ch = c[i];
    int k = p[i];
    if (!a[k]) {
      a[k] = 1;
      if (ch == '-') {
        last = k;
        co++;
      }
    }
  }
  if (co == 0) {
    last = p[0];
  }
  int k = 0;
  if (co != 0) k = 1;
  bool flag = 0;
  for (int i = 0; i < m; i++) {
    if (c[i] == '+') {
      if (p[i] == last && co != 0) {
        flag = 1;
        break;
      }
      if (!k && p[i] != last) {
        flag = 1;
        break;
      } else if (p[i] == last)
        k = 1;
      co++;
    } else {
      if (p[i] == last && co != 1) {
        flag = 1;
        break;
      } else if (p[i] == last)
        k = 0;
      co--;
    }
  }
  int count = 0;
  if (!flag) {
    li[count++] = last;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      li[count++] = i;
    }
  }
  sort(li, li + count);
  printf("%d\n", count);
  for (int i = 0; i < count; i++) printf("%d ", li[i]);
  printf("\n");
}
