#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int counter = 0;
  cin >> n;
  while (n > 0) {
    n -= 1;
    counter++;
    n -= 2;
    if (n < 0) break;
  }
  counter++;
  cout << counter;
}
