#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int result = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '7') result += pow(2, (str.size() - i - 1));
  }
  for (int i = 1; i < str.size(); i++) result += pow(2, i);
  cout << result + 1;
}
