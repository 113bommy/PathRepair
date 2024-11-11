#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  cin >> n;
  bool okay = false;
  for (int i = 1; i <= n; i += 1) {
    if (i * (i + 1) / 2 == n) {
      okay = true;
    }
  }
  if (okay) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
