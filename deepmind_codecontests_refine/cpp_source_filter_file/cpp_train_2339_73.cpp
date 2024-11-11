#include <bits/stdc++.h>
using namespace std;
bool isEven(int a) {
  if (a % 2 == 0) {
    return true;
  }
  return false;
}
void printVec(vector<int> &v) {
  for (auto a : v) cout << a << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<string> v;
  for (int i = 0; i < 3; ++i) {
    string a;
    cin >> a;
    v.push_back(a);
  };
  char result;
  if (v[0] == v[1] && v[1] == v[2]) {
    result = '?';
  } else if (v[0] == v[1] && v[1] != v[2]) {
    if ((v[2] == "rock" && v[1] == "scissor") ||
        (v[2] == "paper" && v[1] == "rock") ||
        (v[2] == "scissor" && v[1] == "paper"))
      result = 'S';
    else
      result = '?';
  } else if (v[1] == v[2] && v[0] != v[2]) {
    if ((v[0] == "rock" && v[1] == "scissor") ||
        (v[0] == "paper" && v[1] == "rock") ||
        (v[0] == "scissor" && v[1] == "paper"))
      result = 'F';
    else
      result = '?';
  } else if (v[0] == v[2] && v[1] != v[2]) {
    if ((v[1] == "rock" && v[0] == "scissor") ||
        (v[1] == "paper" && v[0] == "rock") ||
        (v[1] == "scissor" && v[0] == "paper"))
      result = 'M';
    else
      result = '?';
  } else {
    result = '?';
  }
  cout << result;
  return 0;
}
