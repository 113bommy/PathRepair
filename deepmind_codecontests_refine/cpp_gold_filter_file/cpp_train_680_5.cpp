#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
int n, k, l[MAX], r[MAX];
long long a[MAX], b[MAX];
bool ok() {
  int i, j;
  long long sum;
  i = j = 1;
  while (i <= n && j <= k) {
    sum = 0;
    l[j] = i;
    while (i <= n && (sum + a[i]) <= b[j]) sum += a[i], r[j] = i++;
    if (sum != b[j]) return false;
    j++;
  }
  return true;
}
int pos[MAX], tot;
char op[MAX];
int find(int l, int r) {
  int Max = a[l], index = l;
  for (int i = l + 1; i <= r; i++) {
    if (Max < a[i]) Max = a[i], index = i;
  }
  for (int i = l; i <= r; i++) {
    if (Max == a[i]) {
      if (i > l && a[i - 1] < a[i]) return i;
      if (i < r && a[i + 1] < a[i]) return i;
    }
  }
  return index;
}
void yi(int ps) {
  for (int i = ps; i <= n; i++) a[i] = a[i + 1];
}
bool get(int l, int r) {
  for (int i = 0; i < r - l; i++) {
    int f = find(l, r - i), now = tot;
    if (f == l) {
      if (a[f] > a[f + 1])
        pos[tot] = f, op[tot] = 'R', tot++, a[f] += a[f + 1], yi(f + 1);
    } else if (f == (r - i)) {
      if (a[f] > a[f - 1])
        pos[tot] = f, op[tot] = 'L', tot++, a[f] += a[f - 1], yi(f - 1);
    } else {
      if (a[f] > a[f + 1])
        pos[tot] = f, op[tot] = 'R', tot++, a[f] += a[f + 1], yi(f + 1);
      else if (a[f] > a[f - 1])
        pos[tot] = f, op[tot] = 'L', tot++, a[f] += a[f - 1], yi(f - 1);
    }
    if (now == tot) return false;
  }
  return true;
}
int main() {
  long long suma, sumb;
  suma = sumb = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]), suma += a[i];
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) scanf("%I64d", &b[i]), sumb += b[i];
  if (ok() && suma == sumb) {
    for (int i = 2; i <= k; i++) {
      int tmp = r[i] - l[i];
      l[i] = i;
      r[i] = i + tmp;
    }
    tot = 0;
    bool flag;
    for (int i = 1; i <= k; i++) {
      flag = get(l[i], r[i]);
      if (flag == false) break;
    }
    if (flag == false) {
      printf("NO\n");
      return 0;
    }
    printf("YES\n");
    for (int i = 0; i < tot; i++) printf("%d %c\n", pos[i], op[i]);
  } else
    printf("NO\n");
  return 0;
}
