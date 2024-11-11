#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, close, number, location;
  cin >> n;
  location = -1;
  close = 1000000000;
  number = 0;
  for (long long i = 0; i < n; i++) {
    long long d;
    cin >> d;
    if (d == close) {
      number += 1;
    }
    if (d < close) {
      close = d;
      location = i + 1;
      number = 1;
    }
  }
  if (number > 1) cout << "Still Rozdil" << endl;
  if (number == 1) cout << location << endl;
}
