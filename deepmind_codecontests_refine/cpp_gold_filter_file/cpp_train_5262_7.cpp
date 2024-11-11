#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> jun;
  map<int, int> ndays;
  for (int i = 1000; i < 120000; i++) {
    if (i % 400 == 0) {
      ndays[i] = 366;
    } else if (i % 4 == 0 && i % 100 != 0) {
      ndays[i] = 366;
    } else {
      ndays[i] = 365;
    }
  }
  jun[2016] = 1;
  for (int i = 2017; i < 120000; i++) {
    jun[i] = (jun[i - 1] + ndays[i - 1]) % 7;
  }
  for (int i = 2015; i >= 1000; i--) {
    jun[i] = (jun[i + 1] % 7 - ndays[i] % 7 + 700) % 7;
  }
  int y;
  cin >> y;
  for (int i = y + 1; i < 120000; i++) {
    if (jun[i] == jun[y] && ndays[i] == ndays[y]) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
