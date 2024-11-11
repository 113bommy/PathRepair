#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
char s[maxn], t[maxn];
int n, m;
int judge(int a) {
  int dif = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i + a]) {
      dif++;
    }
  }
  return dif;
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s%s", s, t);
  int mi = 1000, k;
  for (int i = 0; i < m; i++) {
    int temp = judge(i);
    if (temp < mi) {
      mi = temp;
      k = i;
    }
  }
  printf("%d\n", mi);
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i + k]) {
      printf("%d ", i + 1);
    }
  }
  return 0;
}
