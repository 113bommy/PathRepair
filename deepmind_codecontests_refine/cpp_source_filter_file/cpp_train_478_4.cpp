#include <bits/stdc++.h>
using namespace std;
map<string, int> cnt;
int main() {
  int i, j, k, n;
  cin >> n;
  string op;
  string var;
  string newVar;
  while (n--) {
    cin >> op;
    if (op == "typedef") {
      cin >> var;
      cin >> newVar;
      int pnt = 0, amp = 0;
      for (i = var.length() - 1; i >= 0; i--) {
        if (var[i] == '*') {
          pnt++;
          continue;
        } else
          break;
      }
      for (j = 0; j < var.length(); j++) {
        if (var[j] == '&') {
          amp++;
          continue;
        } else
          break;
      }
      string refVar = var.substr(j, i - j + 1);
      if (refVar == "void") {
        cnt[newVar] = pnt - amp;
      } else if (refVar == "errtype") {
        cnt[newVar] = -1;
      } else {
        if (cnt.find(refVar) != cnt.end() && cnt[refVar] >= 0) {
          cnt[newVar] = cnt[refVar] + pnt - amp;
        } else
          cnt[newVar] = -1;
      }
    } else {
      cin >> var;
      int pnt = 0, amp = 0;
      for (i = var.length() - 1; i >= 0; i--) {
        if (var[i] == '*') {
          pnt++;
          continue;
        } else
          break;
      }
      for (j = 0; j < var.length(); j++) {
        if (var[j] == '&') {
          amp++;
          continue;
        } else
          break;
      }
      string refVar = var.substr(j, i - j + 1);
      if ((cnt.find(refVar) != cnt.end() || refVar == "void") &&
          cnt[refVar] >= 0 && cnt[refVar] + pnt - amp >= 0) {
        cout << "void";
        for (i = 0; i < cnt[var] + pnt - amp; i++) {
          cout << "*";
        }
        cout << endl;
      } else {
        cout << "errtype" << endl;
      }
    }
  }
}
