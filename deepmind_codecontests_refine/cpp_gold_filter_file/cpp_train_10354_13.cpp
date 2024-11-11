#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int n;
  int k = 0, m = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  m = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] >= a[i + 1]) {
      k += a[i] - a[i + 1];
    }
    while (a[i] < a[i + 1]) {
      if (a[i] < a[i + 1] && k < a[i + 1] - a[i]) {
        m++;
        a[i]++;
      }
      if (a[i] < a[i + 1] && k >= (a[i + 1] - a[i])) {
        k -= a[i + 1] - a[i];
        a[i] = a[i + 1];
      }
    }
  }
  cout << m;
}
