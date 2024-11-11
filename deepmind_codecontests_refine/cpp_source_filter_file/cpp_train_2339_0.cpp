#include <bits/stdc++.h>
using namespace std;
int main() {
  string F, M, S;
  cin >> F >> M >> S;
  if (M == S && M != F &&
      (M == "rock" && F == "paper" || F == "scissors" && M == "paper" ||
       F == "rock" && M == "scissors"))
    cout << "F\n";
  else if (F == S && F != M &&
           (F == "rock" && M == "paper" || M == "scissors" && F == "paper" ||
            M == "rock" && F == "scissors"))
    cout << "M\n";
  else if (M == F && F != S &&
           (S == "rock" && F == "paper" || S == "scissors" && M == "paper" ||
            S == "rock" && M == "scissors"))
    cout << "S\n";
  else
    cout << "?\n";
  return 0;
}
