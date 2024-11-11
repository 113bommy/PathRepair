#include <bits/stdc++.h>
using namespace std;
inline long long getnum() {
  char c = getchar();
  long long num, sign = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return num * sign;
}
int Tree[400005];
int A[100004], B[100004];
int C[100004], At[100004];
int getmax(int l, int r, int ind, int lx, int rx) {
  if (l == lx && r == rx) return Tree[ind];
  int m = (l + r) / 2;
  if (rx <= m)
    return getmax(l, m, 2 * ind, lx, rx);
  else if (lx > m)
    return getmax(m + 1, r, 2 * ind + 1, lx, rx);
  else
    return max(getmax(l, m, 2 * ind, lx, m),
               getmax(m + 1, r, 2 * ind + 1, m + 1, rx));
}
void update(int l, int r, int ind, int p, int v) {
  if (l == r) {
    Tree[ind] = v;
    return;
  }
  int m = (l + r) / 2;
  if (p <= m)
    update(l, m, 2 * ind, p, v);
  else
    update(m + 1, r, 2 * ind + 1, p, v);
  Tree[ind] = max(Tree[2 * ind], Tree[2 * ind + 1]);
}
int main() {
  int n = getnum(), k = getnum();
  for (int i = 1; i <= n; i++) A[i] = getnum(), B[i] = A[i];
  sort(B + 1, B + n + 1);
  int lim = unique(B + 1, B + n + 1) - B - 1;
  for (int i = 1; i <= n; i++) {
    int l = lower_bound(B + 1, B + lim + 1, A[i]) - B;
    A[i] = l;
  }
  for (int i = 1; i <= k; i++) {
    if (At[A[i]])
      update(1, n, 1, At[A[i]], 0);
    else
      update(1, n, 1, i, A[i]);
    At[A[i]] = i;
    C[A[i]]++;
  }
  int x = getmax(1, n, 1, 1, k);
  if (x)
    printf("%d\n", B[x]);
  else
    printf("NOTHING\n");
  for (int i = 1, j = k; j < n;) {
    C[A[i]]--;
    if (C[A[i]] == 1) update(1, n, 1, At[A[i]], A[i]);
    i++;
    j++;
    C[A[j]]++;
    if (C[A[j]] == 1) update(1, n, 1, j, A[j]);
    if (C[A[j]] == 2) update(1, n, 1, At[A[j]], 0);
    At[A[j]] = j;
    int x = getmax(1, n, 1, i, j);
    if (x)
      printf("%d\n", B[x]);
    else
      printf("Nothing\n");
  }
}
