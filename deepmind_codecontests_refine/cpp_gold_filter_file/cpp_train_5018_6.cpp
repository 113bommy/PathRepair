#include <bits/stdc++.h>
using namespace std;
int main() {
  long t;
  cin >> t;
  while (t--) {
    long a, b;
    long count = 0;
    cin >> a >> b;
    if (a == b) {
      cout << 0 << endl;
      continue;
    }
    if (a < b) swap(a, b);
    long req = a - b;
    count += req / 5;
    req = req % 5;
    count += req / 2;
    req = req % 2;
    count += req / 1;
    req = req % 1;
    cout << count << endl;
  }
}
