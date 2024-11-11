#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp;
  cin >> n;
  int a[n];
  int m = 15000;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int price = 0;
    for (int j = 0; j < a[i]; j++) {
      cin >> temp;
      price += temp * 5 + 15;
    }
    if (price < m) {
      m = price;
    }
  }
  cout << m;
  return 0;
}
