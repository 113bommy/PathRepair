#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int test, size, limit;
  cin >> test;
  while (test--) {
    cin >> size;
    cin >> limit;
    if (size <= 2) {
      cout << 1 << endl;
    } else {
      if ((size - 2) % limit == 0) {
        cout << size / limit + 1 << endl;
      } else {
        cout << (size - 2) / limit + 2 << endl;
      }
    }
  }
  return 0;
}
