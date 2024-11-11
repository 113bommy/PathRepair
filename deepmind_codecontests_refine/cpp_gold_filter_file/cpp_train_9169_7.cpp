#include <bits/stdc++.h>
using namespace std;
int a[101], n, t = 1, ans;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 1; i < n; i++)
    if (a[i] == a[i - 1])
      t++;
    else {
      if (t > ans) ans = t;
      t = 1;
    }
  if (t > ans) ans = t;
  cout << max(1, ans);
}
