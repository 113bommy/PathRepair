#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3;
int main() {
  cin >> s1 >> s2 >> s3;
  if (s2 == s3 &&
      (s1 == "rock" && s2 == "scissors" || s1 == "scissors" && s2 == "paper" ||
       s1 == "paper" && s2 == "rock"))
    puts("F");
  else if (s1 == s3 &&
           (s2 == "rock" && s3 == "scissors" ||
            s2 == "scissors" && s3 == "paper" || s2 == "paper" && s3 == "rock"))
    puts("W");
  else if (s2 == s1 &&
           (s3 == "rock" && s2 == "scissors" ||
            s3 == "scissors" && s2 == "paper" || s3 == "paper" && s2 == "rock"))
    puts("S");
  else
    puts("?");
  return 0;
}
