#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, d, sum = 0, total = 0;
  cin >> n >> b >> d;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (a[i] > b) continue;
    sum += a[i];
    if (sum > d) {
      sum = 0;
      total++;
    }
  }
  cout << total;
  return 0;
}
