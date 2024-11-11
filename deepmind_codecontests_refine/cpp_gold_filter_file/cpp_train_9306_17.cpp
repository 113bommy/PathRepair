#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, d;
  cin >> n >> d;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long quantity = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) {
        if (abs(a[i] - a[j]) <= d) {
          quantity++;
        }
      }
    }
  }
  cout << quantity << endl;
  return 0;
}
