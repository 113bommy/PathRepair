#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s1;
  cin >> s2;
  cin >> s3;
  if ((s1 == "rock" && s2 == "scissors" && s3 == "scissors") ||
      (s1 == "scissors" && s2 == "paper" && s3 == "paper") ||
      (s1 == "paper" && s2 == "rock" && s3 == "rock"))
    cout << 'F' << endl;
  else if ((s2 == "rock" && s1 == "scissors" && s3 == "scissors") ||
           (s2 == "scissors" && s1 == "paper" && s3 == "paper") ||
           (s2 == "paper" && s1 == "rock" && s3 == "rock"))
    cout << 'M' << endl;
  else if ((s3 == "rock" && s2 == "scissors" && s1 == "scissors") ||
           (s3 == "scissors" && s2 == "paper" && s1 == "paper") ||
           (s3 == "paper" && s2 == "rock" && s1 == "rock"))
    cout << 'F' << endl;
  else
    cout << '?' << endl;
  return 0;
}
