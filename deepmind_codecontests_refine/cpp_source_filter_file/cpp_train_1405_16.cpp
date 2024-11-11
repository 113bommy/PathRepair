#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[1001], b[1001] = {};
  for (int i = 0; i < n; i++) cin >> a[i];
  int k = a[0];
  for (int i = 0; i < n; i++) {
    k = -k;
    a[i] = a[i] + k;
    if (a[i] > 5)
      a[i] -= n;
    else if (a[i] < 0)
      a[i] += n;
  }
  k = 0;
  for (int i = 1; i < n; i++) b[i] = b[i - 1] + 1;
  for (int i = 0; i < n; i++)
    if (a[i] == b[i]) k++;
  if (k == n)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
