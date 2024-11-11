#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int k = 0;
    int n1 = n;
    int c = 0;
    while (n1 > 0) {
      n1 = n1 / 10;
      c++;
      k += c;
    }
    int n2 = (n % 10) * 10 - 10;
    cout << n2 + k << endl;
  }
  return 0;
}
