#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  bool E = true;
  for (int i = 0; i < S.size(); i++){
    if (i % 2 == 0 && S[i] == 'L' || i % 2 == 1 && S[i] == 'R') E = false;
  }
  cout << (E ? "Yes" : "No");
}