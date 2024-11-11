#include <bits/stdc++.h>
using namespace std;
int n, bus, big, in, out;
int main() {
  big = -1000;
  cin >> n >> bus >> bus;
  n -= 2;
  big = bus;
  while (--n) {
    cin >> in >> out;
    bus += (-in + out);
    if (bus > big) big = bus;
  }
  cout << big << endl;
  return 0;
}
