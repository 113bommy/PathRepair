#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long pc = 0, nc = 0;
  bool res = true;
  for (long long i = 0; i < n; i++) {
    long long tempx, tempy;
    cin >> tempx >> tempy;
    if (tempx > 0)
      pc++;
    else
      nc++;
    if (pc == 2 && nc == 2) {
      res = false;
      break;
    }
  }
  if (res)
    cout << "Yes\n";
  else
    cout << "No\n";
}
