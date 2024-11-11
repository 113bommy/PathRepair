#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  if (s1 == "paper" && s2 == "rock" && s3 == "rock") {
    cout << "F" << endl;
  } else if (s1 == "rock" && s2 == "paper" && s3 == "rock") {
    cout << "M" << endl;
  } else if (s1 == "rock" && s2 == "rock" && s3 == "paper") {
    cout << "M" << endl;
  } else if (s1 == "paper" && s2 == "paper" && s3 == "scissors") {
    cout << "S" << endl;
  } else if (s1 == "scissors" && s2 == "paper" && s3 == "paper") {
    cout << "F" << endl;
  } else if (s1 == "paper" && s2 == "scissors" && s3 == "paper") {
    cout << "M" << endl;
  } else if (s1 == "rock" && s2 == "scissors" && s3 == "scissors") {
    cout << "F" << endl;
  } else if (s1 == "scissors" && s2 == "scissors" && s3 == "rock") {
    cout << "S" << endl;
  } else if (s1 == "scissors" && s2 == "rock" && s3 == "scissors") {
    cout << "M" << endl;
  } else {
    cout << "?" << endl;
  }
}
