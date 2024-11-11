#include <bits/stdc++.h>
using namespace std;
bool case1(int x) { return x & 1; }
bool case2(int x) { return x & 2; }
bool case3(int x) { return x & 4; }
int parse() {
  char ch;
  if ((ch = getchar()) == '(') {
    int l = parse();
    char op = getchar();
    int r = parse();
    getchar();
    int res = 0;
    if (op == '&') {
      if (case1(l) || case1(r) || (case3(l) && case3(r))) {
        res += 1;
      }
      if (case2(l) && case2(r)) {
        res += 2;
      }
      if ((case3(l) && (case2(r) || case3(r))) ||
          (case3(r) && (case2(l) || case3(l)))) {
        res += 4;
      }
      return res;
    }
    if (op == '|') {
      if (case1(l) && case2(r)) {
        res += 1;
      }
      if (case2(l) || case2(r) || (case3(l) && case3(r))) {
        res += 2;
      }
      if ((case3(l) && (case1(r) || case3(r))) ||
          (case3(r) && (case1(l) || case3(l)))) {
        res += 4;
      }
      return res;
    }
    if (op == '^') {
      if ((case1(l) && case1(r)) || (case2(l) && case2(r)) ||
          (case3(l) && case3(r))) {
        res += 1;
      }
      if ((case1(l) && case2(r)) || (case2(l) && case1(r)) ||
          (case3(l) && case3(r))) {
        res += 2;
      }
      if ((case3(l) && (case1(r) || case2(r))) ||
          (case3(r) && (case1(l) || case2(l)))) {
        res += 4;
      }
      return res;
    }
  } else {
    if (ch == '0') return 1;
    if (ch == '1') return 2;
    return 4;
  }
}
int main() {
  int n;
  cin >> n;
  getchar();
  cout << (case3(parse()) ? "YES" : "NO") << endl;
}
