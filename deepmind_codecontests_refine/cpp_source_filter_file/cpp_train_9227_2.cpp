#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = (int)1e9 + 7;
const int N = (int)1e6 + 7;
int n, x1, x2;
pair<int, int> a[N];
void Init() {
  for (int i = (0); i < (n); ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i + 1;
  }
  sort(a, a + n);
}
int Solve() {
  for (int i = (0); i < (n); ++i) {
    int num1 = (x1 + a[i].first - 1) / a[i].first;
    int pos = i + num1;
    if (pos >= n) continue;
    int num2 = (x2 + a[pos].first - 1) / a[pos].first;
    if (pos + num2 > n) continue;
    printf("Yes\n%d %d\n", num1, num2);
    for (int j = (0); j < (num1); ++j)
      printf("%d%c", a[i + j].second, " \n"[j == num1 - 1]);
    for (int j = (0); j < (num2); ++j)
      printf("%d%c", a[pos + j].second, " \n"[j == num2 - 1]);
    return 0;
  }
  swap(x1, x2);
  for (int i = (0); i < (n); ++i) {
    int num1 = (x1 + a[i].first - 1) / a[i].first;
    int pos = i + num1;
    if (pos >= n) continue;
    int num2 = (x2 + a[pos].first - 1) / a[pos].first;
    if (pos + num2 > n) continue;
    printf("Yes\n%d %d\n", num1, num2);
    for (int j = (0); j < (num2); ++j)
      printf("%d%c", a[pos + j].second, " \n"[j == num2 - 1]);
    for (int j = (0); j < (num1); ++j)
      printf("%d%c", a[i + j].second, " \n"[j == num1 - 1]);
    return 0;
  }
  return puts("No");
}
int main() {
  while (~scanf("%d%d%d", &n, &x1, &x2)) {
    Init();
    Solve();
  }
  return 0;
}
