#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[3005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  if (a[1] <= a[n / 2])
    cout << "Bob";
  else
    cout << "Alice";
  return 0;
}
