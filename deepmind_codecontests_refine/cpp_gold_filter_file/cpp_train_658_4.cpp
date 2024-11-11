#include <bits/stdc++.h>
using namespace std;
bool inSize(int c, int l, int r) {
  if (c >= l && c <= r) return true;
  return false;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int maxn = 10001;
int ret[maxn];
int n, x, y, mx;
int a[50];
int b[50];
int main() {
  memset(ret, 0, sizeof(ret));
  mx = -1;
  scanf("%d", &(x));
  for (int i = 0; i < x; i++) {
    scanf("%d", &(a[i]));
  }
  scanf("%d", &(y));
  for (int i = 0; i < y; i++) {
    scanf("%d", &(b[i]));
  }
  for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++)
      if (b[j] % a[i] == 0) {
        int t = b[j] / a[i];
        ret[t]++;
        mx = max(mx, t);
      }
  printf("%d", (ret[mx]));
  printf("\n");
  ;
}
