#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, k;
  cin >> n >> k;
  if (k % n != 0) {
    cout << "NO";
  } else {
    int count = 0;
    while (k >= 2) {
      k = k / n;
      count++;
      if (k % n != 0 && k != 1) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES"
         << "\n";
    cout << count - 1;
  }
  return 0;
}
