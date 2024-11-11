#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    while (n != 0) {
      if (n % 2 == 0) {
        cout << "I hate";
        n--;
      }
      if (n % 2 != 0) {
        cout << " that I love";
        n--;
      }
      if (n != 0) cout << " that ";
    }
    cout << " it";
  }
  if (n % 2 != 0) {
    while (n != 0) {
      if (n % 2 != 0) {
        cout << "I hate";
        n--;
      }
      if (n % 2 == 0 && n != 0) {
        cout << "that I love";
        n--;
      }
      if (n != 0) cout << " that ";
    }
    cout << " it";
  }
}
