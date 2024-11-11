#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
bool beat(string a, string b) {
  if (a == "rock" && b == "sciccors") return true;
  if (a == "sciccors" && b == "paper") return true;
  if (a == "paper" && b == "rock") return true;
  return false;
}
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  if (beat(a, b) && beat(a, c))
    cout << "F";
  else if (beat(b, a) && beat(b, c))
    cout << "M";
  else if (beat(c, a) && beat(c, b))
    cout << "S";
  else
    cout << "?";
  cout << endl;
  return 0;
}
