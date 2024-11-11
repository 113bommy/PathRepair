#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, d, sum = 0, k = 0;
  cin >> n >> h >> d;
  int ar[n];
  for (int i = 0; i < n; i++) cin >> ar[i];
  for (int i = 0; i < n; i++) {
    if (ar[i] < h) {
      sum = sum + ar[i];
      if (sum > d) {
        sum = 0;
        k++;
      } else
        continue;
    } else
      continue;
  }
  cout << k << endl;
  return 0;
}
