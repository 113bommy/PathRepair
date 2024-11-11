#include <bits/stdc++.h>
using namespace std;
long long sl[100500], sr[100500], s[100500];
int a[100500];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) scanf("%d", a + i);
  sl[0] = 0;
  for (int i = 1; i < n; i++)
    if (a[i] > 1)
      sl[i] = sl[i - 1] + a[i] - a[i] % 2;
    else
      sl[i] = 0;
  sr[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--)
    if (a[i + 1] > 1)
      sr[i] = sr[i + 1] + a[i + 1] - a[i + 1] % 2;
    else
      sr[i] = 0;
  s[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--)
    s[i] = max(sr[i], s[i + 1] + a[i + 1] - (a[i + 1] - 1) % 2);
  long long mx = 0;
  for (int i = 0; i < n; i++)
    if (sl[i] + s[i] > mx) mx = sl[i] + s[i];
  cout << mx << endl;
  return 0;
}
