#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int size = str.size();
  int subsize = size - 1;
  while (true) {
    bool found = false;
    for (int i = 0; i < size - subsize; i++) {
      string sub = str.substr(i, subsize);
      if (str.find(sub) != str.rfind(sub)) {
        found = true;
        break;
      }
    }
    if (found == true || subsize == 0) {
      break;
    } else {
      subsize--;
    }
  }
  cout << subsize << endl;
}
