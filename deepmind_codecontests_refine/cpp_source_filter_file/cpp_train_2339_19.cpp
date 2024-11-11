#include <bits/stdc++.h>
using namespace std;
bool check(string a, string b) {
  if ((a == ("paper") && b == ("rock")) || (a == "scissor" && b == "paper") ||
      (a == "rock" && b == "scissor"))
    return true;
  else
    return false;
}
int main() {
  vector<string> v;
  for (int i = 0; i < 3; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  if (check(v[0], v[1]) && check(v[0], v[2]))
    cout << "F" << endl;
  else if (check(v[1], v[0]) && check(v[1], v[2]))
    cout << "M" << endl;
  else if (check(v[2], v[1]) && check(v[2], v[0]))
    cout << "S" << endl;
  else
    cout << "?" << endl;
}
