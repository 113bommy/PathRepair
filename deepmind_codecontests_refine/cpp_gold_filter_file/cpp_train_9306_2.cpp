#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n >> d;
  int count = 0, a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (abs(a[i] - a[j]) <= d && i != j) {
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}
