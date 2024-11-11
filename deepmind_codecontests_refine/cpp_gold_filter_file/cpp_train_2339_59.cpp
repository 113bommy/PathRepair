#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 * 100 + 100;
int a, b;
string s1, s2, s3;
int main() {
  cin >> s1 >> s2 >> s3;
  if ((s1 == s2 && s2 == s3) || (s1 != s2 && s2 != s3 && s3 != s1) ||
      (s1 == s2 && s2 == "rock" && s3 == "scissors") ||
      (s1 == s2 && s2 == "paper" && s3 == "rock") ||
      (s1 == s2 && s2 == "scissors" && s3 == "paper") ||
      (s1 == s3 && s3 == "rock" && s2 == "scissors") ||
      (s1 == s3 && s3 == "paper" && s2 == "rock") ||
      (s1 == s3 && s3 == "scissors" && s2 == "paper") ||
      (s3 == s2 && s2 == "rock" && s1 == "scissors") ||
      (s3 == s2 && s2 == "paper" && s1 == "rock") ||
      (s3 == s2 && s2 == "scissors" && s1 == "paper"))
    cout << "?" << endl;
  else {
    if ((s1 == s2 && s2 == "rock" && s3 == "paper") ||
        (s1 == s2 && s2 == "paper" && s3 == "scissors") ||
        (s1 == s2 && s2 == "scissors" && s3 == "rock"))
      cout << "S" << endl;
    else if ((s1 == s3 && s3 == "rock" && s2 == "paper") ||
             (s1 == s3 && s3 == "paper" && s2 == "scissors") ||
             (s1 == s3 && s3 == "scissors" && s2 == "rock"))
      cout << "M" << endl;
    else
      cout << "F" << endl;
  }
  return 0;
}
