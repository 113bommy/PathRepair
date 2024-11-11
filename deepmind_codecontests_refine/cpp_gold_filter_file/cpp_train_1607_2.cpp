#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1[3], a2[3], i;
  cin >> a1[0] >> a1[1] >> a1[2];
  cin >> a2[0] >> a2[1] >> a2[2];
  for (i = 0; i < 3; i++) {
    if (a1[i] == a2[i]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
