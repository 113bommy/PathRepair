#include <bits/stdc++.h>
using namespace std;
long long n, a[100005], sol = 0;
int main() {
  scanf("%I64d", &n);
  long long pluss = 0;
  for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
  int cost = a[1];
  int energie = 0;
  for (int i = 1; i < n; ++i)
    if (a[i] + energie < a[i + 1])
      cost += a[i + 1] - a[i] - energie, energie = 0;
    else if (a[i] > a[i + 1])
      energie += a[i] - a[i + 1];
    else
      energie -= (a[i + 1] - a[i]);
  cout << cost;
  return 0;
}
