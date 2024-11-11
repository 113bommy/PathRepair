#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a[4], i, j;
  for (i = 0; i < 4; i++) {
    cin >> a[i];
  }
  for (i = 0; i < 4; i++) {
    for (j = i + 1; j < 4; j++) {
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
      }
    }
  }
  cout << a[3] - a[0] << " " << a[3] - a[1] << " " << a[3] - a[2];
  return 0;
}
