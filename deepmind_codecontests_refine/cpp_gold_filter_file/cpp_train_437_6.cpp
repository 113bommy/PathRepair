#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int count = 1;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i < n; i++) {
      if (a[i] != a[i + 1]) count++;
    }
    printf("%d\n", count);
  }
  return 0;
}
