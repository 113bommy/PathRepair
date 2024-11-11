#include <bits/stdc++.h>
using namespace std;
const int N = 5E5 + 7;
int a[N], b[N];
int n;
int main() {
  cin >> n;
  int x;
  int top = -1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    while (top >= 1 && a[top - 1] >= a[top] && a[top] <= x) {
      ans = ans + min(x, a[top - 1]);
      top--;
    }
    top++;
    a[top] = x;
  }
  sort(a, a + top + 1);
  for (int i = 0; i < top - 1; i++) {
    ans = ans + a[i];
  }
  cout << ans << endl;
  return 0;
}
