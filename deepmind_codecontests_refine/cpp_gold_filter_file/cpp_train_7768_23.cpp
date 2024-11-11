#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[100005];
int main() {
  cin >> n >> x;
  if (n == 0)
    printf("YES\n");
  else {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum = sum + a[i];
    }
    if (sum + n - 1 == x)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
