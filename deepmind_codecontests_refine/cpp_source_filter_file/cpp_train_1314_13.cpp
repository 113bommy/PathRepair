#include <bits/stdc++.h>
using namespace std;
int n, a = 1023, b = 0, x, aa[11], bb[11], op1, op2, op3;
char op, what[12];
int main() {
  cin >> n;
  while (n > 0) {
    cin >> op >> x;
    if (op == '&') {
      a = a & x;
      b = b & x;
    }
    if (op == '^') {
      a = a ^ x;
      b = b ^ x;
    }
    if (op == '|') {
      a = a | x;
      b = b | x;
    }
    n = n - 1;
  }
  for (int i = 0; i <= 9; i++) aa[i] = bb[i] = 0;
  int n1 = 0, n2 = 0;
  while (a) {
    aa[n1] = a % 2;
    a = a / 2;
    n1 = n1 + 1;
  }
  while (b) {
    bb[n2] = b % 2;
    b = b / 2;
    n2 = n2 + 1;
  }
  for (int i = 0; i <= 9; i++) {
    if (aa[i] == 0 and bb[i] == 0) what[i] = '&', op1 = 1;
    if (aa[i] == 1 and bb[i] == 1) what[i] = '|', op2 = 1;
    if (aa[i] == 1 and bb[i] == 0) what[i] = '0';
    if (aa[i] == 0 and bb[i] == 1) what[i] = '^', op3 = 1;
  }
  cout << op1 + op2 + op3 << "\n";
  if (op1 == 1) {
    x = 0;
    n = 1;
    for (int i = 0; i <= 9; i++) {
      if (what[i] != '&') x = x + n;
      n = n * 2;
    }
    cout << "& " << x << "\n";
  }
  if (op2 == 1) {
    x = 0;
    n = 1;
    for (int i = 0; i <= 9; i++) {
      if (what[i] == '|') x = x + n;
      n = n * 2;
    }
    cout << "| " << x << "\n";
  }
  if (op3 == 1) {
    x = 0;
    n = 1;
    for (int i = 0; i <= 9; i++) {
      if (what[i] == '^') x = x + n;
      n = n * 2;
    }
    cout << "^ " << n << "\n";
  }
  return 0;
}
