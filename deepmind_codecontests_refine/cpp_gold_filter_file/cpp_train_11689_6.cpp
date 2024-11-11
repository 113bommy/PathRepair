#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long a[3], b[3];
  for (int i = 0; i < 3; i++) cin >> a[i];
  for (int i = 0; i < 3; i++) cin >> b[i];
  long long ans1 = 0;
  if (a[0] < b[1])
    ans1 += a[0];
  else
    ans1 += b[1];
  if (a[1] < b[2])
    ans1 += a[1];
  else
    ans1 += b[2];
  if (a[2] < b[0])
    ans1 += a[2];
  else
    ans1 += b[0];
  long long ans2 = 0;
  for (int i = 0; i < 3; i++) {
    a[i] -= min(a[i], b[i]);
  }
  for (int i = 0; i < 3; i++) {
    int j = (i - 1 + 3) % 3;
    if (a[i] < b[j]) {
      b[j] -= a[i];
      a[i] = 0;
    } else {
      a[i] -= b[j];
      b[j] = 0;
    }
  }
  if (a[0] < b[1])
    ans2 += a[0];
  else
    ans2 += b[1];
  if (a[1] < b[2])
    ans2 += a[1];
  else
    ans2 += b[2];
  if (a[2] < b[0])
    ans2 += a[2];
  else
    ans2 += b[0];
  cout << ans2 << " " << ans1 << endl;
  return 0;
}
