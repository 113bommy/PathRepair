#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  for (int i = 0; i <= 9; i++) {
    cout << i << endl;
    getline(cin, str);
    if (str == "no")
      continue;
    else if (str == "cool" || str == "great" || str == "don't think so" ||
             str == "not bad" || str == "don't touch me") {
      printf("normal\n");
      break;
    } else {
      printf("grumpy\n");
      break;
    }
  }
}
