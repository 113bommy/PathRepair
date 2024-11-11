#include <bits/stdc++.h>
using namespace std;
int days;
string currentA, currentB, choose, rep;
int main() {
  cin >> currentA >> currentB;
  cout << currentA << " " << currentB;
  cin >> days;
  for (int i = 0; i < days; i++) {
    cin >> choose >> rep;
    if (choose == currentA) {
      currentA = rep;
    } else {
      currentB = rep;
    }
    cout << currentA << " " << currentB << endl;
  }
}
