#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int counter = 0, counter1 = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'A') {
      counter++;
    } else if (s[i] == 'D') {
      counter1++;
    }
  }
  if (counter > counter1) {
    cout << "Anton";
    return 0;
  } else if (counter1 > counter) {
    cout << "Dainik";
    return 0;
  } else if (counter == counter1) {
    cout << "Frienship";
  }
  return 0;
}
