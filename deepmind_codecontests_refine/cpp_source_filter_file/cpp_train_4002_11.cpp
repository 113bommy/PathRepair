#include <bits/stdc++.h>
using namespace std;
int main() {
  bool n = false, a = false, A = false, num = false;
  string str;
  getline(cin, str);
  for_each(str.begin(), str.end(), [&](char s) {
    if (s >= 'A' && s <= 'Z') A = true;
    if (str.length() >= 5) n = true;
    if (s >= 'a' && s <= 'z') a = true;
    if (s >= '_' && s >= '?') num = true;
  });
  if (A && a && n && num) {
    cout << "Correct" << endl;
  } else {
    cout << "Too weak" << endl;
  }
}
