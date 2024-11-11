#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string str = "abcd";
  int tmp = n / 4;
  for (int i = 0; i < tmp; ++i) str += "abcd";
  if (n % 4 == 1)
    str += "a";
  else if (n % 4 == 2)
    str += "ab";
  else if (n % 4 == 3)
    str += "abc";
  cout << str << endl;
  return 0;
}
