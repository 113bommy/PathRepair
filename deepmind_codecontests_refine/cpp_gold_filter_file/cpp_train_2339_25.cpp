#include <bits/stdc++.h>
using namespace std;
bool ck(string b, string a) {
  if (a == "rock" && b == "paper") return true;
  if (a == "paper" && b == "scissors") return true;
  if (a == "scissors" && b == "rock") return true;
  return false;
}
int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  if (s1 == s2 && ck(s3, s2)) {
    cout << "S";
    return 0;
  }
  if (s1 == s3 && ck(s2, s3)) {
    cout << "M";
    return 0;
  }
  if (s3 == s2 && ck(s1, s2)) {
    cout << "F";
    return 0;
  }
  cout << "?";
  return 0;
}
