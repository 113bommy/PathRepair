#include <bits/stdc++.h>
using namespace std;
int main(void) {
  string s;
  cin >> s;
  int n = s.length();
  int i = 0;
  int b = s.find("WUB");
  if (b != -1) {
    s.replace(b, 3, " ");
    b = s.find("WUB");
  }
  cout << s;
  return 0;
}
