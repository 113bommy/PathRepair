#include <bits/stdc++.h>
using namespace std;
const int maxC = 2147483647;
const int maxNode = 10230997;
const int maxN = 1000000;
string str;
int n, z[maxN];
void buildZ(string& str) {
  z[0] = 0;
  int l = 0;
  for (int i = 1; i < (int)str.size(); ++i) {
    while (l && str[i] != str[l]) l = z[l - 1];
    if (str[i] == str[l]) ++l;
    z[i] = l;
  }
}
int main() {
  cin >> str;
  buildZ(str);
  int res = z[str.size() - 1];
  bool kt = 0;
  for (int i = 0; i < (int)str.size() - 1; ++i) {
    if (z[i] == res) {
      kt = 1;
      break;
    }
  }
  if (!kt) {
    res = z[res - 1];
  }
  if (res == 0)
    cout << "Just a legend";
  else
    cout << str.substr(0, res);
  return (0);
}
