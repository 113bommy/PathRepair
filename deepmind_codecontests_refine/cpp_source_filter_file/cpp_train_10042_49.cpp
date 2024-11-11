#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  cin >> num;
  for (int i = 1;; i++) {
    if ((i * (i + 1) / 2) == num) {
      cout << "YES";
      break;
    } else if ((i * (i + 1) / 2) < num) {
      cout << "NO";
      break;
    }
  }
}
