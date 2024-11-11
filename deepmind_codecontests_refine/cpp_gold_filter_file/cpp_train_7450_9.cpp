#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, count = 1;
  cin >> n >> k;
  if (k % 2 != 0) {
    cout << "1";
  } else {
    while (k % 2 == 0) {
      k = k / 2;
      count++;
    }
    cout << count;
  }
  return 0;
}
