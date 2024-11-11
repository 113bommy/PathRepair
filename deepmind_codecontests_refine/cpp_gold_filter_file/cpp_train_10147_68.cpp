#include <bits/stdc++.h>
using namespace std;
struct RTC {
  ~RTC() { cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC << " seconds\n"; }
} runtimecount;
int main() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << "white" << endl;
    cout << 1 << " " << 2 << endl;
  } else {
    if (n % 2 == 0) {
      cout << "white" << endl;
      cout << 1 << " " << 2 << endl;
    } else {
      cout << "black" << endl;
    }
  }
  return 0;
}
