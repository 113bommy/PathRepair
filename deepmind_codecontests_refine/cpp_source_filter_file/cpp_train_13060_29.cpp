#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << 4 << " " << n - 4 << endl;
  } else {
    cout << 6 << " " << n - 6 << endl;
  }
}
