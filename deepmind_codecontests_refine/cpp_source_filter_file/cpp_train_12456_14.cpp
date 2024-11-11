#include <bits/stdc++.h>
using namespace std;
int main() {
  int flag, n;
  cin >> n;
  int a[n + 5];
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (i == a[a[a[i]]]) {
      flag = 1;
      break;
    }
  }
  if (flag)
    printf("YES\n");
  else
    printf("NO\n");
}
