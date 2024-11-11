#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  getline(cin, str);
  while (str.back() < 'A') {
    str.pop_back();
  }
  if (str.back() < 'Z') {
    str.back() = str.back() + 32;
  }
  if (str.back() == 'a' || str.back() == 'e' || str.back() == 'i' ||
      str.back() == 'o' || str.back() == 'u' || str.back() == 'y') {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
