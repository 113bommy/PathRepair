#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, i, a, count = 0;
  cin >> t >> n;
  int arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  i = 0;
  while (t > 0 && i < n) {
    if (arr[i] < 86400) {
      a = 86400 - arr[i];
      t = t - a;
      count++;
    } else
      count++;
    i++;
  }
  cout << count;
}
