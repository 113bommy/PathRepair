#include <bits/stdc++.h>
using namespace std;
int main() {
  int coun = 0;
  int need = 0;
  string str;
  cin >> str;
  for (int i = 1; i <= str.length(); i++) {
    coun++;
    if (str[i] != str[i - 1]) {
      if (!(coun & 1)) need++;
      coun = 0;
    }
  }
  cout << need << endl;
}
