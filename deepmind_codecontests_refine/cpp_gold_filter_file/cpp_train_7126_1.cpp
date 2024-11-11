#include <bits/stdc++.h>
using namespace std;
struct diem {
  int val, pos;
};
const int maxn = 100005;
int n, A, B;
int p[maxn], isA[maxn] = {0}, isB[maxn] = {0};
int ans[maxn], lab[maxn];
diem a[maxn];
void nhap() {
  scanf("%d %d %d", &n, &A, &B);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].val);
    p[i] = i;
    a[i].pos = i;
  }
  if (n == 1 && A == 1 && B == 1) {
    printf("NO");
    exit(0);
  }
}
bool cmp(diem a, diem b) { return a.val < b.val; }
int get(int x) { return (p[x] == x) ? x : (p[x] = get(p[x])); }
void hopnhat(int x, int y) {
  x = get(x);
  y = get(y);
  if (rand() & 1) swap(x, y);
  p[x] = y;
}
void solve() {
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1, j = n; i <= j; i++) {
    while (a[i].val + a[j].val > A) j--;
    if (a[i].val + a[j].val == A) {
      hopnhat(i, j);
      isA[i] = 1;
      isA[j] = 1;
    }
  }
  for (int i = 1, j = n; i <= j; i++) {
    while (a[i].val + a[j].val > B) j--;
    if (a[i].val + a[j].val == B) {
      hopnhat(i, j);
      isB[i] = 1;
      isB[j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) p[i] = get(i);
}
void answer() {
  int flag = 1;
  for (int i = 1; i <= n; i++) {
    if (isA[i] == 0 && isB[i] == 0) {
      flag = 0;
      break;
    }
    if (!isA[i]) {
      if (lab[p[i]] && lab[p[i]] != 2) {
        flag = 0;
        break;
      } else
        lab[p[i]] = 2;
    }
    if (!isB[i]) {
      if (lab[p[i]] && lab[p[i]] != 1) {
        flag = 0;
        break;
      } else
        lab[p[i]] = 1;
    }
  }
  if (!flag)
    printf("NO");
  else {
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
      if (!lab[i]) lab[i] = 1;
    }
    for (int i = 1; i <= n; i++) ans[a[i].pos] = lab[p[i]] - 1;
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  }
}
int main() {
  nhap();
  solve();
  answer();
  return 0;
}
