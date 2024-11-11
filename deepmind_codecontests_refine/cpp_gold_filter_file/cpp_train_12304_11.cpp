#include <bits/stdc++.h>
using namespace std;
int main() {
  int dA, dB;
  cin >> dA >> dB;
  if (dB - dA == 1) {
    cout << dA << " " << dB << endl;
  } else if (dA == 9 && dB == 1) {
    cout << "9 10" << endl;
  } else if (dA == dB) {
    cout << dA << "0 " << dB << "1" << endl;
  } else {
    cout << -1 << endl;
  }
}
