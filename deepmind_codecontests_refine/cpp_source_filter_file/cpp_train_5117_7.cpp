#include <bits/stdc++.h>
using namespace std;
const string Straight = "AEFHIKLMNTVWXYZ";
int main() {
  string s;
  cin >> s;
  bool flag_s = false, flag_c = false;
  for (char c : s) {
    if (find(Straight.begin(), Straight.end(), c) == Straight.end()) {
      flag_s = true;
    } else {
      flag_c = true;
    }
  }
  puts(flag_s ^ flag_c ? "no" : "yes");
  return 0;
}
