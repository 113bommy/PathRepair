#include <bits/stdc++.h>
using namespace std;
int main() {
  string Trap;
  int Target, Hacked = 0;
  cin >> Target;
  for (int i = 0; i < Target; i++) {
    string Target;
    cin >> Target;
    if (Target == "0") return cout << 0, 0;
    bool Assest = false;
    for (int i = 1; i < Target.size(); i++)
      if (Target[i] != '0') Assest = true;
    if (Assest == true || Target[0] != '1')
      Trap = Target;
    else
      Hacked = Target.size() - 1;
  }
  if (Trap == "") {
    cout << 1;
    for (int i = 0; i < Hacked; i++) cout << 0;
  } else {
    cout << Trap;
    for (int i = 0; i < Hacked; i++) cout << 0;
  }
  return 0;
}
