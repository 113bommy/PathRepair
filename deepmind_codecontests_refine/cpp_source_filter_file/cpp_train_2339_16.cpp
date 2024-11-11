#include <bits/stdc++.h>
using namespace std;
int main() {
  string name1, name2, name3;
  cin >> name1;
  cin >> name2;
  cin >> name3;
  string r = "rock";
  string s = "scissor";
  string p = "paper";
  if (name1 == r && name2 == s && name3 == s)
    cout << "F" << endl;
  else if (name1 == p && name2 == r && name3 == r)
    cout << "F" << endl;
  else if (name1 == s && name2 == p && name3 == p)
    cout << "F" << endl;
  else if (name1 == s && name2 == r && name3 == s)
    cout << "M" << endl;
  else if (name1 == r && name2 == p && name3 == r)
    cout << "M" << endl;
  else if (name1 == p && name2 == s && name3 == p)
    cout << "M" << endl;
  else if (name1 == s && name2 == s && name3 == r)
    cout << "S" << endl;
  else if (name1 == r && name2 == r && name3 == p)
    cout << "S" << endl;
  else if (name1 == p && name2 == p && name3 == s)
    cout << "S" << endl;
  else
    cout << "?" << endl;
  return 0;
}
