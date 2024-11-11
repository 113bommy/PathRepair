#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y;
  cin >> n >> x >> y;
  long long var = n - 1;
  x -= var;
  y -= var;
  long long num = y;
  bool ok = 0;
  while (num >= 0) {
    if (num <= y & num * num >= x) {
      ok = 1;
      cout << num << endl;
      break;
    }
    num--;
  }
  if (!ok) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n - 1; i++) {
      cout << 1 << endl;
    }
  }
}
