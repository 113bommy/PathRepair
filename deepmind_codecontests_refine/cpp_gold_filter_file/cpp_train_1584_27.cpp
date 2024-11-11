#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << 9 << " " << 8 << endl;
  } else {
    cout << n * 3 << " " << n * 2 << endl;
  }
  return 0;
}
