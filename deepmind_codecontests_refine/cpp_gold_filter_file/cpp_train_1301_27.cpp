#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int a[1000000], da[1000000];
  ;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) da[i] = 10 - a[i] % 10;
  for (int dk = 1; dk <= 10 && k >= dk; dk++) {
    for (int i = 0; i < n && k >= dk; i++)
      if (da[i] == dk && a[i] + dk != 110) {
        a[i] += dk;
        k -= dk;
        da[i] = 10;
      }
    if (dk == 10)
      for (int i = 0; i < n; i++)
        while (k >= 10 && a[i] != 100) {
          a[i] += 10;
          k -= 10;
        }
  }
  int sum = 0;
  for (int i = 0; i < n; i++) sum += a[i] / 10;
  cout << sum;
  return 0;
}
