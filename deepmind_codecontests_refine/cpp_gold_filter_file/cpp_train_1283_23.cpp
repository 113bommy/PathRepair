#include <bits/stdc++.h>
using namespace std;
const int maxN = 200000;
char ch[maxN];
int a[maxN], b[maxN], c[maxN], x[maxN], n, m;
int main() {
  scanf("%d %d\n", &n, &m);
  int k = 0;
  for (int i = 1; i <= n; i++) {
    cin >> ch[i] >> x[i];
    if (ch[i] == '+')
      a[x[i]]++;
    else {
      b[x[i]]++;
      k++;
    }
  }
  int y = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] + (k - b[i]) == m) c[i] = 1;
    y += c[i];
  }
  for (int i = 1; i <= n; i++) {
    if (ch[i] == '-') {
      if (c[x[i]] == 0)
        printf("Truth\n");
      else if (y > 1)
        printf("Not defined\n");
      else
        printf("Lie\n");
    } else {
      if (c[x[i]] == 0)
        printf("Lie\n");
      else {
        if (y > 1)
          printf("Not defined\n");
        else
          printf("Truth\n");
      }
    }
  }
  return 0;
}
