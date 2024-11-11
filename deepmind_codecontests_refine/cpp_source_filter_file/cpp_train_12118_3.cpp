#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int atk[maxn], m1;
int def[maxn], m2;
int p[maxn], n;
bool used[maxn];
int m;
int main() {
  scanf("%d%d", &m, &n);
  m1 = m2 = 0;
  for (int i = 0; i < m; i++) {
    char s[5];
    int x;
    scanf("%s%d", s, &x);
    if (s[0] == 'A')
      atk[m1++] = x;
    else
      def[m2++] = x;
  }
  for (int i = 0; i < n; i++) scanf("%d", &p[i]);
  sort(atk, atk + m1);
  sort(def, def + m2);
  sort(p, p + n);
  int ans1 = 0, ans2 = 0;
  int i, j, k;
  for (i = j = 0; i < m2; i++) {
    while (j < n && p[j] <= def[i]) j++;
    if (j < n) {
      used[j] = 1;
      j++;
    } else
      break;
  }
  if (i == m2) {
    for (k = j = 0; k < m1; k++) {
      while (j < n && (used[j] || p[j] < atk[k])) j++;
      if (j < n)
        j++;
      else
        break;
    }
    if (k == m1) {
      for (j = 0; j < n; j++)
        if (!used[j]) ans1 += p[j];
      for (k = 0; k < m1; k++) ans1 -= atk[k];
    }
  }
  for (int s = 0; s < min(n, m1); s++) {
    bool flag = 1;
    int temp = 0;
    for (j = n - s, k = 0; j < n; j++, k++) {
      if (p[j] >= atk[k])
        temp += p[j] - atk[k];
      else {
        flag = 0;
        break;
      }
    }
    if (flag) ans2 = max(ans2, temp);
  }
  printf("%d\n", max(ans1, ans2));
}
