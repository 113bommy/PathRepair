#include <bits/stdc++.h>
using namespace std;
const int maxN = 1010;
int n, h;
int a[maxN];
int b[maxN];
bool judge(int x) {
  long long cost = 0;
  for (int i = 1; i <= x; i++) b[i] = a[i];
  sort(b + 1, b + n + 1);
  for (int i = x; i >= 1; i -= 2) {
    cost += b[i];
  }
  return (long long)h >= cost;
}
int main() {
  scanf("%d %d", &n, &h);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  a[n + 1] = h + 1;
  if (a[1] > h) {
    puts("0");
    return 0;
  }
  int l = 1, r = n + 1;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (judge(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;
  return 0;
}
