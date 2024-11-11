#include <bits/stdc++.h>
using namespace std;
int n, d, res, a[1000];
int ABS(int x) {
  if (x < 0) x = -x;
  return x;
}
int main() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (ABS(a[i] - a[j]) <= d) res++;
  res *= 2;
  cout << res;
}
