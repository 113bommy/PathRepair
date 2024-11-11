#include <bits/stdc++.h>
using namespace std;
int n, a[1005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++)
    if (abs(a[i] - a[i + 1]) >= 2) {
      puts("NO");
      return 0;
    }
  puts("YES");
  return 0;
}
