#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (auto a : v) out << a << " ";
  return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& a : v) in >> a;
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, multiset<T>& S) {
  for (auto a : S) out << a << " ";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, set<T>& S) {
  for (auto a : S) out << a << " ";
  return out;
}
template <typename T>
set<T> operator+(set<T> A, set<T> B) {
  for (auto b : B) A.insert(b);
  return A;
}
int main() {
  char ch;
  int w = 0;
  int b = 0;
  while (cin >> ch) {
    if (ch == 'Q') {
      w += 9;
    } else if (ch == 'R') {
      w += 5;
    } else if (ch == 'B') {
      w += 3;
    } else if (ch == 'K') {
      w += 3;
    } else if (ch == 'P') {
      w += 1;
    } else if (ch == 'q') {
      b += 9;
    } else if (ch == 'r') {
      b += 5;
    } else if (ch == 'b') {
      b += 3;
    } else if (ch == 'k') {
      b += 3;
    } else if (ch == 'p') {
      b += 1;
    }
  }
  if (w > b)
    cout << "White" << endl;
  else if (w < b)
    cout << "Black" << endl;
  else
    cout << "Draw" << endl;
  return 0;
}
