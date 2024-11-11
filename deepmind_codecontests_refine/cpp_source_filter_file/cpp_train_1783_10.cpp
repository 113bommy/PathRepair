#include <bits/stdc++.h>
using namespace std;
string InvDir(string dir) {
  string invDir;
  if (dir == "u") {
    invDir = "d";
  } else if (dir == "d") {
    invDir = "u";
  } else if (dir == "l") {
    invDir = "r";
  } else {
    invDir = "l";
  }
  return invDir;
}
string CopyCellDir(string dir) {
  string invDir = InvDir(dir);
  string ans = dir + "10" + invDir + "t" + invDir + "s" + dir + "t";
  return ans;
}
string AnsString() {
  string ans;
  string copyCellDown = CopyCellDir("d");
  string copyCellUp = CopyCellDir("u");
  string copyCellLeft = CopyCellDir("l");
  string copyCellRight = CopyCellDir("r");
  string copyRowDown = copyCellDown;
  for (int i = 1; i < 4; ++i) {
    copyRowDown += ("l" + copyCellDown);
  }
  for (int i = 1; i < 4; ++i) {
    copyRowDown += "r";
  }
  string xorCell = "1010utrtdt", carryCell = "1100utrtdt";
  string additionCell = carryCell + copyCellLeft + xorCell + copyCellRight +
                        "l" + copyCellRight + "r";
  string additionRow = additionCell;
  for (int i = 1; i < 4; ++i) {
    additionRow += ("l" + additionCell);
  }
  ans = copyRowDown;
  ans += "u";
  ans += copyRowDown;
  ans += "dd";
  ans += copyRowDown;
  ans += "r0l";
  ans += additionRow;
  return ans;
}
int main() {
  cout << AnsString() << '\n';
  return 0;
}
