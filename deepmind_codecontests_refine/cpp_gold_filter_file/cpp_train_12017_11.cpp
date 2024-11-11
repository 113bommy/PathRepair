#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  int A = 0, B = 0, C = 0, add = 0, equals = 0;
  cin >> a;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '+') {
      add++;
    }
    if (a[i] == '=') {
      equals++;
    }
    if (a[i] == '|' && add == 0) {
      A++;
    } else if (a[i] == '|' && equals == 0) {
      B++;
    } else if (a[i] == '|' && add == 1 && equals == 1) {
      C++;
    }
  }
  if (A + B > C + 2 || A + B < C - 2 || A + B == C + 1 || A + B == C - 1) {
    cout << "Impossible";
    return 0;
  }
  if (A + B == C) {
    for (int i = 0; i < A; i++) {
      cout << '|';
    }
    cout << '+';
    for (int i = 0; i < B; i++) {
      cout << '|';
    }
    cout << '=';
    for (int i = 0; i < C; i++) {
      cout << '|';
    }
    return 0;
  }
  if (A + B == C + 2) {
    if (A >= B) {
      A--;
      C++;
    } else if (B > A) {
      B--;
      C++;
    }
    for (int i = 0; i < A; i++) {
      cout << '|';
    }
    cout << '+';
    for (int i = 0; i < B; i++) {
      cout << '|';
    }
    cout << '=';
    for (int i = 0; i < C; i++) {
      cout << '|';
    }
    return 0;
  }
  if (A + B == C - 2) {
    if (A <= B) {
      A++;
      C--;
    } else if (B < A) {
      B++;
      C--;
    }
    for (int i = 0; i < A; i++) {
      cout << '|';
    }
    cout << '+';
    for (int i = 0; i < B; i++) {
      cout << '|';
    }
    cout << '=';
    for (int i = 0; i < C; i++) {
      cout << '|';
    }
    return 0;
  }
  return 0;
}
