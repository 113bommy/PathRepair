#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  cin >> n >> s;
  int countA = 0, countD = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') countA++;
    if (s[i] == 'D') countD++;
  }
  if (countA > countD) {
    cout << "Anton" << endl;
  } else if (countA < countD) {
    cout << "Danik" << endl;
  } else {
    cout << "FriendShip" << endl;
  }
  return 0;
}
