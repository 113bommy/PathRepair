#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, n, count = 0;
  cin >> d >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] < d) {
      count = count + d - a[i];
    }
  }
  cout << count;
}
