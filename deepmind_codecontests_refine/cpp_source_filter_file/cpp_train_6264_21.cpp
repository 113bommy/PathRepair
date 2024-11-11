#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], t, p = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == n) t = i;
  }
  for (int i = 0; i < t; i++)
    if (a[i] < a[i + 1]) p++;
  for (int i = t; i < n; i++)
    if (a[i] > a[i + 1]) p++;
  if (p + 1 == n)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
