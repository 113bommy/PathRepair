#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1)
    cout << "4\n";
  else {
    string finAns = "";
    int len = 0;
    int n2 = n;
    while (n2 > 0 && len <= 18) {
      if (n2 - 2 >= 0) {
        n2 -= 2;
        finAns += "8";
        len++;
      } else {
        n2 -= 1;
        finAns += "0";
        len++;
      }
    }
    if (n2 > 0 || len > 18)
      cout << "-1\n";
    else
      cout << finAns << '\n';
  }
}
