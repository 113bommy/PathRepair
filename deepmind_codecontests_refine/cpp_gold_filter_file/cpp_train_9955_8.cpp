#include <bits/stdc++.h>
using namespace std;
int main() {
  string S, T;
  bool C = false;
  getline(cin, S);
  for (int i = 0; i < S.length(); i++) {
    if (S[i] != 'D' && S[i] != 'A' && S[i] != 'O' && S[i] != 'S' && S[i] != 'N')
      continue;
    if (S[i] == 'D') {
      T = S.substr(i, 5);
      if (T == "Danil") {
        if (C == true) {
          cout << "NO";
          return 0;
        }
        C = true;
      }
    } else if (S[i] == 'O') {
      T = S.substr(i, 4);
      if (T == "Olya") {
        if (C == true) {
          cout << "NO";
          return 0;
        }
        C = true;
      }
    } else if (S[i] == 'S') {
      T = S.substr(i, 5);
      if (T == "Slava") {
        if (C == true) {
          cout << "NO";
          return 0;
        }
        C = true;
      }
    } else if (S[i] == 'A') {
      T = S.substr(i, 3);
      if (T == "Ann") {
        if (C == true) {
          cout << "NO";
          return 0;
        }
        C = true;
      }
    } else if (S[i] == 'N') {
      T = S.substr(i, 6);
      if (T == "Nikita") {
        if (C == true) {
          cout << "NO";
          return 0;
        }
        C = true;
      }
    }
  }
  if (C == true)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
