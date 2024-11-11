#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int rooms;
    cin >> rooms;
    string stairs;
    cin >> stairs;
    int firstPos = stairs.find("1");
    int lastPos = stairs.rfind("1");
    if (firstPos == string::npos) {
      cout << rooms << "\n";
    } else {
      int wasted = min(firstPos, rooms - lastPos - 1);
      cout << 2 * (rooms - wasted) << "\n";
    }
  }
  return 0;
}
