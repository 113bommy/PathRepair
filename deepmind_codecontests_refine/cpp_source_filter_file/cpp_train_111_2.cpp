#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int amin = a[0], oppV = a[0];
  for (int i = 1; i < n; i++) {
    if (a[0] < a[i]) amin = a[i];
    oppV = oppV + a[i];
  }
  long int totalV, k;
  for (int j = amin; j < 10000; j++) {
    totalV = j * n;
    if (totalV - oppV > oppV) {
      cout << j;
      return 0;
    }
  }
}
