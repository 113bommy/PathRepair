#include <bits/stdc++.h>
using namespace std;
long long abs1(long long a) {
  if (a < 0)
    return -a;
  else
    return a;
}
int main() {
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    b[i] = a[i];
  }
  sort(b.begin(), b.end());
  vector<long long> tek(n);
  vector<long long> next(n);
  for (int i = 0; i < n; i++)
    if (i == 0)
      tek[i] = abs1(a[0] - b[i]);
    else
      tek[i] = min(tek[i - 1], abs1(a[0] - b[i]));
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++)
      if (j == 0)
        next[j] = tek[j] + abs1(a[i + 1] - b[j]);
      else
        next[j] = min(next[j - 1], tek[j] + abs1(a[i + 1] - b[j]));
    swap(tek, next);
    next.clear();
    next.resize(n);
  }
  printf("%lld", tek[n - 1]);
  return 0;
}
