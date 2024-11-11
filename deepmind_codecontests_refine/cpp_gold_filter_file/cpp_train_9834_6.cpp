#include <bits/stdc++.h>
using namespace std;
int n;
bool bus[34];
int main() {
  cin >> n;
  memset(bus, false, sizeof bus);
  cout << "+------------------------+" << endl;
  for (int i = 0; i < n; i++) {
    bus[i] = true;
  }
  cout << "|";
  if (bus[0])
    cout << "O.";
  else
    cout << "#.";
  for (int i = 4; i < 34; i += 3) {
    if (bus[i])
      cout << "O.";
    else
      cout << "#.";
  }
  cout << "|D|)" << endl;
  cout << "|";
  if (bus[1]) {
    cout << "O.";
  } else
    cout << "#.";
  for (int i = 5; i < 34; i += 3) {
    if (bus[i])
      cout << "O.";
    else
      cout << "#.";
  }
  cout << "|.|" << endl;
  cout << "|";
  if (bus[2]) {
    cout << "O.";
  } else
    cout << "#.";
  cout << "......................|" << endl;
  cout << "|";
  if (bus[3]) {
    cout << "O.";
  } else
    cout << "#.";
  for (int i = 6; i < 34; i += 3) {
    if (bus[i])
      cout << "O.";
    else
      cout << "#.";
  }
  cout << "|.|)" << endl;
  cout << "+------------------------+";
  return 0;
}
