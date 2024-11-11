#include <bits/stdc++.h>
using namespace std;
void adskiy_razgon() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int MAX = 2e5 + 7;
const int MOD = 1e+9 + 7;
const long long INF = 1e+18 + 7;
int nod(int a, int b) {
  if (a == 0 || b == 0) {
    return 0;
  } else if (a == b) {
    return a;
  } else if (a > b) {
    return nod(a - b, b);
  } else {
    return nod(a, b - a);
  }
}
int nok(int a, int b) { return a * b / nod(a, b); }
void sp(int a, double b) { cout << fixed << setprecision(a) << b; }
set<string> s;
int main() {
  adskiy_razgon();
  string a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  s.insert(a1);
  s.insert(a2);
  s.insert(a3);
  if (s.size() == 3 || s.size() == 1) {
    cout << '?';
    return 0;
  }
  if (a1 == "paper") {
    if (a2 == "rock" && a3 == "rock") {
      cout << "F";
      return 0;
    }
  } else if (a1 == "rock") {
    if (a2 == "scissors" && a3 == "scissors") {
      cout << "F";
      return 0;
    }
  } else if (a1 == "scissors") {
    if (a2 == "paper" && a3 == "paper") {
      cout << "F";
      return 0;
    }
  }
  if (a2 == "paper") {
    if (a1 == "rock" && a2 == "rock") {
      cout << "M";
      return 0;
    }
  } else if (a2 == "rock") {
    if (a1 == "scissors" && a3 == "scissors") {
      cout << "M";
      return 0;
    }
  } else if (a2 == "scissors") {
    if (a1 == "paper" && a3 == "paper") {
      cout << "M";
      return 0;
    }
  }
  if (a3 == "paper") {
    if (a1 == "rock" && a2 == "rock") {
      cout << "S";
      return 0;
    }
  } else if (a3 == "rock") {
    if (a2 == "scissors" && a1 == "scissors") {
      cout << "S";
      return 0;
    }
  } else if (a3 == "scissors") {
    if (a2 == "paper" && a1 == "paper") {
      cout << "S";
      return 0;
    }
  }
  cout << "?";
  return 0;
}
