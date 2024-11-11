#include <bits/stdc++.h>
using namespace std;
int main() {
  int in, k;
  cin >> in >> k;
  for (int i = 0; i < k; i++) {
    if (in % 10 == 0) {
      in /= 10;
    } else {
      in -= 1;
    }
  }
  cout << in;
}
