#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a;
  cin >> b;
  int counter1 = 0, counter2 = 0;
  for (unsigned int i = 0; i < a.size(); i++) {
    if (a[i] == '4' && b[i] == '7') {
      counter1++;
    }
    if (a[i] == '7' && b[i] == '4') {
      counter2++;
    }
  }
  if (counter1 > counter2) {
    cout << counter2;
  } else {
    cout << counter1;
  }
  return 0;
}
