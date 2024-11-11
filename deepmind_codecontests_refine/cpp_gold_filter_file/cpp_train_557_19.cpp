#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  int s = 0;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  for (int i = 0; i < n; i++) {
    s = s + a[i];
    if (s <= 500) {
      cout << "A";
    } else {
      cout << "G";
      s = s - b[i] - a[i];
    }
  }
}
