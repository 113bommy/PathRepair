#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
int n;
long long mas[300005];
long long ans;
int main() {
  time_t start = clock();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &mas[i]);
  }
  sort(mas, mas + n);
  for (int i = 1; i <= n; i++) mas[i] += mas[i - 1];
  for (int i = 1; i <= n; i++) ans += (mas[n] - mas[i - 1]);
  ans += mas[n - 1] - mas[0];
  cout << ans;
  fprintf(stderr, "\n%0.3lf\n", (clock() - start) * 1.0 / CLOCKS_PER_SEC);
  return 0;
}
