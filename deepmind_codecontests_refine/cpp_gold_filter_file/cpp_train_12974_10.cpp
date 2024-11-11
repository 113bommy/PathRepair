#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, a[100];
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int day = 0;
  for (int i = 0; i < n; i++) {
    t -= 86400 - a[i];
    day++;
    if (t <= 0) {
      printf("%d\n", day);
      return 0;
    }
  }
  return 0;
}
