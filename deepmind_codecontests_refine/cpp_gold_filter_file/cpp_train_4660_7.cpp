#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 5;
int a[N], bit[N];
int n;
void add(int x) {
  for (; x <= n; x += x & (-x)) bit[x]++;
}
int sum(int x) {
  int s = 0;
  for (; x; x -= x & (-x)) s += bit[x];
  return s;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    add(a[i]);
    cnt = (cnt + (i - sum(a[i]))) % 2;
  }
  if (3 * n % 2 + cnt % 2 == 1)
    printf("Um_nik\n");
  else
    printf("Petr\n");
  return 0;
}
