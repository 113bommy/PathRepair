#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int no;
  int min = INT_MAX;
  int max = INT_MIN;
  for (int i = 1; i <= n; i++) {
    cin >> no;
    if (no > max) {
      max = no;
    }
    if (no < min) {
      min = no;
    }
  }
  cout << max - min + 1 - n;
  return 0;
}
