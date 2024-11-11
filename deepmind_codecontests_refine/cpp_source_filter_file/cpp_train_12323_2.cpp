#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int i = 0; i < 8; i++) {
    string inp;
    cin >> inp;
    for (int j = 0; j < 7; j++) {
      if (inp[i] == inp[i + 1]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
