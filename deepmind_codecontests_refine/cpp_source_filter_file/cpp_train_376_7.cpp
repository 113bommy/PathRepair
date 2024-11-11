#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, x2;
  int bigger;
  int smaller;
  int sum = 0;
  int counter1 = 0;
  int counter2 = 0;
  cin >> x1 >> x2;
  if (x1 > x2) {
    bigger = x1;
    smaller = x2;
  } else {
    bigger = x2;
    smaller = x2;
  }
  for (int i = 1; i < bigger; i++) {
    if (smaller == bigger) {
      break;
    }
    smaller++;
    counter1++;
    if (smaller == bigger) {
      break;
    }
    bigger--;
    counter2++;
  }
  for (int i = 1; i <= counter1; i++) {
    sum = sum + i;
  }
  for (int i = 1; i <= counter2; i++) {
    sum = sum + i;
  }
  cout << sum << endl;
  return 0;
}
