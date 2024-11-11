#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int i = 0; i < 4; i++) {
    cout << i << endl;
    string s;
    getline(cin, s);
    if (s == "no") {
      continue;
    }
    if (s == "don't even" || s == "are you serious?" ||
        s == "go die in a hole" || s == "worse" || s == "terrible" ||
        s == "no way") {
      cout << "grumpy" << endl;
      return 0;
    } else {
      cout << "normal" << endl;
      return 0;
    }
  }
  cout << "normal" << endl;
  return 0;
}
