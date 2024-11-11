#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.size() - 1; i++) {
    if (str[i] == '.') {
      cout << 0;
    } else if (str[i] == '-' && str[i + 1] == '.') {
      i++;
      cout << 1;
    } else if (str[i] == '-' && str[i + 1] == '-') {
      cout << 2;
      i++;
    }
  }
  cout << endl;
  return 0;
}
