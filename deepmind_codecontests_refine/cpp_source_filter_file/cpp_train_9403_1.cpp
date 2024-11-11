#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, a[100000], j, count = 0;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (j = 0; j < n; j++) {
    if (a[j] >= a[k] && a[j] > 0) {
      count = count + 1;
    }
  }
  cout << count << endl;
  return 0;
}
