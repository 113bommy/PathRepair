#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[1000], a, maxi = 0, k = 0, arb[1000001];
  cin >> n;
  for (int i = 0; i <= 1000000; i++) {
    arb[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a;
    arr[i] = a;
  }
  for (int g = 0; g < n; g++) {
    k = 0;
    for (int i = g; i < n; i++) {
      if (arr[i] == arr[g]) k++;
    }
    if (k > maxi) maxi = k;
  }
  for (int i = 0; i < n; i++) {
    arb[arr[i]]++;
    if (arb[arr[i]] == maxi) {
      cout << arr[i];
      break;
    }
  }
  return 0;
}
