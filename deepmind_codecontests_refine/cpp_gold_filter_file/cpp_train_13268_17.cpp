#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int counter = 0;
  cin >> n;
  int a, b;
  while (n--) {
    cin >> a >> b;
    if (b - a >= 2) {
      counter++;
    }
  }
  cout << counter << endl;
  return 0;
}
