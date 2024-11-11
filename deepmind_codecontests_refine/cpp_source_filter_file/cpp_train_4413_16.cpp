#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100], t, s, sum = 0, summ = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> s >> t;
  if (s > t) {
    swap(s, t);
  }
  for (int i = s - 1; i < t - 1; i++) sum += a[i];
  for (int i = t - 1; i < n; i++) summ += a[i];
  for (int i = 1; i < s - 1; i++) summ += a[i];
  if (summ > sum)
    cout << sum;
  else
    cout << summ;
}
