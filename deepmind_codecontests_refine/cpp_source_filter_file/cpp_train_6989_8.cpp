#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  for (int i = 1000000; i >= 1; i++) {
    int curr = k + i;
    if (curr % 2000 == 0) {
      cout << "2000\n";
      for (int i = 0; i < 1998; i++) cout << "0 ";
      cout << (curr / 2000) - i << " " << i << endl;
      return 0;
    }
  }
  return 0;
}
