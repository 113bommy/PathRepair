#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, size;
    long long boo = 0;
    cin >> n >> size;
    long long** arr = new long long*[(n * 2) + 1];
    for (size_t i = 0; i < (n * 2); ++i) arr[i] = new long long[3];
    for (long long i = 0; i < n * 2; i++) {
      cin >> arr[i][0];
      cin >> arr[i][1];
    }
    for (long long i = 0; i <= n; i += 2) {
      if (arr[i][1] == arr[i + 1][0]) {
        boo = 1;
      }
    }
    if ((size % 2 != 0) || (size == 0)) {
      boo = 0;
    }
    if (boo == 1)
      cout << "YES";
    else {
      cout << "NO";
    }
    cout << endl;
  }
  return 0;
}
