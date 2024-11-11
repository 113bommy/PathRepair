#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, l;
  cin >> k >> l;
  for (long long i = 1; i < sqrt(l); i++) {
    if (pow(k, i) == l) {
      cout << "Yes" << endl;
      cout << i - 1 << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
