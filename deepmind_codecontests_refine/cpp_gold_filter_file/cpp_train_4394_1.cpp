#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k, a[N], b, x[N], top, l[N], r[N];
char ch[N];
int main() {
  scanf("%d %d", &n, &k);
  scanf("%s", ch + 1);
  for (int i = 1; i <= n; i++) a[i] = a[i + n] = ch[i] == 'B';
  for (int i = 2; i <= n + 1; i++)
    if (a[i] == a[i - 1]) {
      b = i;
      break;
    }
  if (b == 0) {
    if ((k & 1) == 0)
      printf("%s", ch + 1);
    else
      for (int i = 1; i <= n; i++) putchar(ch[i] == 'W' ? 'B' : 'W');
  } else {
    if (b == n + 1) b = 1;
    x[b] = x[b + n - 1] = 1;
    for (int i = b + 1; i <= b + n - 1; i++)
      if (a[i] == a[i - 1] || a[i] == a[i + 1]) x[i] = 1;
    for (int i = b + 1; i <= b + n - 2; i++) {
      if (x[i] == 0 && x[i - 1] == 1) l[++top] = i;
      if (x[i] == 0 && x[i + 1] == 1) r[top] = i;
    }
    for (int i = 1; i <= top; i++)
      if (r[i] - l[i] + 1 <= k * 2) {
        if (a[l[i] - 1] == a[r[i] + 1])
          for (int j = l[i]; j <= r[i]; j++)
            a[j] = a[(((j - n > 0) ? (j - n) : (j + n)))] = a[l[i] - 1];
        else {
          for (int j = l[i]; j <= (l[i] + r[i]) / 2; j++)
            a[j] = a[(((j - n > 0) ? (j - n) : (j + n)))] = a[l[i] - 1];
          for (int j = (l[i] + r[i]) / 2 + 1; j <= r[i]; j++)
            a[j] = a[(((j - n > 0) ? (j - n) : (j + n)))] = a[r[i] + 1];
        }
      } else {
        for (int j = 0; j < k; j++)
          a[l[i] +
            j] = a[(((l[i] + j - n > 0) ? (l[i] + j - n) : (l[i] + j + n)))] =
              a[l[i] - 1],
            a[r[i] - j] =
                a[(((r[i] - j - n > 0) ? (r[i] - j - n) : (r[i] - j + n)))] =
                    a[r[i] + 1];
        if (k & 1)
          for (int j = l[i] + k; j <= r[i] - k; j++)
            a[j] = a[(((j - n > 0) ? (j - n) : (j + n)))] = !a[j];
      }
    for (int i = 1; i <= n; i++) putchar(a[i] ? 'B' : 'W');
  }
  return 0;
}
