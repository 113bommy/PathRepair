#include <bits/stdc++.h>
using namespace std;
struct node {
  int p, d;
} s[100010];
int a[100010];
int b[100010];
bool cmp(const node n1, const node n2) { return n1.p < n2.p; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> s[i].p;
    s[i].d = i;
  }
  sort(s, s + n, cmp);
  for (int i = 0; i < n / 3; i++) {
    a[s[i].d] = i;
    b[s[i].d] = s[i].p - i;
  }
  for (int i = n / 3; i < 2 * (n / 3); i++) {
    a[s[i].d] = s[i].p - i;
    b[s[i].d] = i;
  }
  for (int i = 2 * (n / 3); i < n; i++) {
    a[s[i].d] = s[i].p - (n - 1 - i);
    b[s[i].d] = (n - 1 - i);
  }
  printf("YES\n");
  printf("%d", a[0]);
  for (int i = 1; i < n; i++) printf(" %d", a[i]);
  printf("\n");
  printf("%d", b[0]);
  for (int i = 1; i < n; i++) printf(" %d", b[i]);
  printf("\n");
  return 0;
}
