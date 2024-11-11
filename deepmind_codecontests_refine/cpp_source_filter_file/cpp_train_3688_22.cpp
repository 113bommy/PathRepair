#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ar[n];
  for (int i = 0; i < n - 1; i++) {
    cin >> ar[i];
  }
  int a, b;
  cin >> a >> b;
  int sum = 0;
  for (int i = 0;; i++) {
    if (a == b) {
      cout << sum << endl;
      break;
    }
    a = a + 1;
    sum = sum + ar[i];
  }
}
