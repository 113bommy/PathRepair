#include <bits/stdc++.h>
using namespace std;
int q, n;
char a[200100], b[200100], ta[50], tb[50], tc[50];
int sa[30], sb[30];
int p[1000], sum;
void gb(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  gb(l, mid);
  gb(mid + 1, r);
  int i = l, j = mid + 1, w = l - 1;
  while (i <= mid && j <= r) {
    if (p[tc[i]] <= p[tc[j]]) {
      ta[++w] = tc[i++];
    } else {
      sum += mid - i + 1;
      ta[++w] = tc[j++];
    }
  }
  while (i <= mid) ta[++w] = tc[i++];
  while (j <= r) ta[++w] = tc[j++];
  for (i = l; i <= r; i++) tc[i] = ta[i];
}
void work() {
  memset(sa, 0, sizeof(sa));
  memset(sb, 0, sizeof(sb));
  scanf("%d", &n);
  cin >> a;
  cin >> b;
  for (int i = 0; i < n; i++) {
    sa[a[i] - 'a' + 1]++;
    sb[b[i] - 'a' + 1]++;
  }
  for (int i = 1; i <= 26; i++) {
    if (sa[i] != sb[i]) {
      printf("NO\n");
      return;
    }
  }
  for (int i = 1; i <= 26; i++) {
    if (sa[i] >= 2) {
      printf("YES\n");
      return;
    }
  }
  sum = 0;
  for (int i = 0; i < n; i++) p[a[i]] = i;
  for (int i = 1; i <= n; i++) tc[i] = b[i - 1];
  gb(1, n);
  if (sum % 2)
    printf("NO\n");
  else
    printf("YES\n");
}
int main() {
  scanf("%d", &q);
  while (q--) work();
  return 0;
}
