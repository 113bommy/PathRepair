#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n], max = 1, count = 1;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i + 1])
      count++;
    else {
      if (count > max) max = count;
      count = 1;
    }
  }
  if (count > max) max = count;
  cout << max;
}
