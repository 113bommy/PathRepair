#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i = 0, count = 0;
    while (count < n) {
      i++;
      if (i % 3 != 0 && i % 10 != 3) {
        count++;
      }
    }
    cout << i << "\n";
  }
  return 0;
}
