#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int main() {
  int n = 4, a[4];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + 4);
  if (a[0] + a[3] == a[1] + a[2] || a[0] + a[2] == a[1] + a[3])
    puts("YES");
  else
    puts("NO");
}
