#include <bits/stdc++.h>
using namespace std;
int a[10007];
int main() {
  int n, x;
  int max = 0;
  cin >> n;
  memset(a, 0, sizeof(a));
  while (n--) {
    cin >> x;
    a[x]++;
    if (x > max) max = x;
  }
  int ans = 1;
  for (int i = max - 1; i > 0; i--) {
    if (max % i == 0) a[i]--;
    if (a[i]) {
      ans = i;
      break;
    }
  }
  cout << max << " " << ans;
}
