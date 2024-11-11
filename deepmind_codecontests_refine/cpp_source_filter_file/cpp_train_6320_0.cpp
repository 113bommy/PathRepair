#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int i, a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  int count = 0;
  i = 0;
  int j = n - 1;
  while (i < j) {
    if (a[i] <= k) {
      i++;
      count++;
    } else {
      if (a[j] <= k) {
        j--;
        count++;
      } else {
        break;
      }
    }
  }
  cout << count << endl;
}
