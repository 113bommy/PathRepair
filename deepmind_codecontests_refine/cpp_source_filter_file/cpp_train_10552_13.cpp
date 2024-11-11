#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int size = str.size();
  int subSize = size - 1;
  while (true) {
    bool found = false;
    for (int i = 0; i < size - subSize; i++) {
      string sub = str, substr(i, subSize);
      if (str.find(sub) != str.rfind(sub)) {
        found = true;
        break;
      }
    }
    if (found == true || subSize == 0) {
      break;
    } else {
      subSize--;
    }
  }
  cout << subSize << endl;
}
