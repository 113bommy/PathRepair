#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int a[200], b[200];
  b[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = b[i - 1] + a[i];
  }
  int l = -1, r = -1, max = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int n1 = b[j] - b[i - 1];
      int n0 = j - i + 1 - n1;
      int adv = n0 - n1;
      if (adv > max) {
        max = adv;
        l = i;
        r = j;
      }
    }
  }
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (i >= l && i <= r) {
      if (a[i] == 0) count++;
    } else {
      if (a[i] == 1) count++;
    }
  }
  if (max == -1) count--;
  cout << count;
  return 0;
}
