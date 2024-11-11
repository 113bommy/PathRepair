#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> vec;
  int lol, result;
  for (int i = 0; i < 4; i++) {
    cin >> lol;
    vec.push_back(lol);
  }
  string str;
  cin >> str;
  int len = str.length();
  for (int i = 0; i < len; i++) {
    int x = str[i] - '0';
    result += vec[x - 1];
  }
  cout << result << endl;
  return 0;
  ;
}
