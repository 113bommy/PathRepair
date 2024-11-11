#include <bits/stdc++.h>
using namespace std;
int main() {
  long a[5000];
  int n, b, k, l;
  cin >> n >> b;
  int maxx = n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    l = b / a[i];
    k = b % a[i];
    for (int j = i + 1; j <= n; j++)
      if (l * a[j] + k > maxx) maxx = l * a[j] + k;
  }
  if (maxx > b)
    cout << maxx;
  else
    cout << b;
  return 0;
}
