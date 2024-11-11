#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  for (int i = 0; i < 2; i++) {
    string c;
    cin >> c;
    s += c;
  }
  string a;
  for (int i = 0; i < 2; i++) {
    string c;
    cin >> c;
    a += c;
  }
  set<string> myset = {"ABCX", "CABX", "BCAX", "ABXC", "CAXB", "BCXA",
                       "XCBA", "XBAC", "XACB", "CXBA", "BXAC", "AXCB"};
  if (myset.find(s) != myset.end() && myset.find(s) != myset.end()) {
    cout << "YES\n";
  } else if (myset.find(s) == myset.end() && myset.find(s) == myset.end()) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
