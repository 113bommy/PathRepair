#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  string in;
  cin >> s >> in;
  int j = 0;
  int c = 0;
  for (int i = 0; i < sizeof(in); i++) {
    if (in[i] == s[j]) {
      c++;
      j = j + 1;
    }
  }
  cout << c + 1 << endl;
}
