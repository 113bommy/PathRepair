#include <bits/stdc++.h>
using namespace std;
int main() {
  char n[9];
  for (int i = 0; i < 9; i++) {
    cin >> n;
  }
  if (n[0] == n[8] && n[1] == n[7] && n[2] == n[6] && n[3] == n[5]) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
