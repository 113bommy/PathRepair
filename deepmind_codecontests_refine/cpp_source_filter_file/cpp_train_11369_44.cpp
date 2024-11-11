#include <bits/stdc++.h>
using namespace std;
int main() {
  string data;
  cin >> data;
  string res = "";
  string d = "";
  int i = 0;
  while (i < data.length()) {
    if (data[i] == '<' && data[i + 2] == '>') {
      res += d + data.substr(i, i + 3) + "\n";
      d += "  ";
      i += 3;
    } else {
      d = d.substr(0, d.length() - 2);
      res += d + data.substr(i, i + 4) + "\n";
      i += 4;
    }
  }
  cout << res;
}
