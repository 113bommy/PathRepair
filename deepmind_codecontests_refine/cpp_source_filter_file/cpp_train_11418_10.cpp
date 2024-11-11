#include <bits/stdc++.h>
using namespace std;
bool Pfunc(string);
int main() {
  string st;
  cin >> st;
  for (int i = st.size(); i > 0; i--) {
    bool b = false;
    for (int k = 0; k < st.size() - i; k++) {
      if (Pfunc(st.substr(k, i + k)) == false) {
        cout << i;
        b = true;
        return 0;
      } else {
      }
    }
    if (b) {
      break;
    }
  }
  cout << 0;
  return 0;
}
bool Pfunc(string x) {
  for (int i = 0; i < x.size() / 2; i++) {
    if (x[i] != x[x.size() - i - 1]) {
      return false;
    }
  }
  return true;
}
