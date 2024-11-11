#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[10050];
  int b[10050];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(b, b + n);
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (b[i] != a[i]) ans++;
  if (ans <= 2)
    printf("YES");
  else
    printf("NO");
  printf("\n");
  return 0;
}
