#include <bits/stdc++.h>
using namespace std;
inline void setIO(string a) {}
int n, a[100005];
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int now = n, Ans = n;
  for (int i = n / 2; i; i--) {
    if (a[now] > a[i] * 2) --now, --Ans;
  }
  printf("%d\n", Ans);
}
