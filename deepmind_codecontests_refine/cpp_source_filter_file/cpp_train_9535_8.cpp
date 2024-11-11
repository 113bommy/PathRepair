#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 99, inf = 1e9;
int n, t, a[N], ans[N];
void odd_case() {
  for (int i = 1; i < n + 1; i++) ans[1] = max(ans[1], a[i]);
  ;
  ans[2] = ans[1];
  for (int i = 2; i < n; i++)
    ans[min(i - 1, n - i) * 2 + 1] =
        max(ans[min(i - 1, n - i) * 2 + 1], min(a[i], max(a[i - 1], a[i + 1])));
  ;
}
void even_case() {
  for (int i = 2; i < n; i++) {
    ans[min(i - 1, n - i) * 2 + 2] =
        max(ans[min(i - 1, n - i) * 2 + 2], max(a[i], min(a[i - 1], a[i + 1])));
    ;
  }
  for (int i = n; i >= 1; i--) ans[i] = max(ans[i], ans[i] + 2);
  ;
}
int main() {
  cin >> n;
  for (int i = 1; i < n + 1; i++) scanf("%d", &a[i]);
  ;
  odd_case();
  even_case();
  for (int i = 0; i < n; i++) cout << ans[n - i] << " ";
}
