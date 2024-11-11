#include <bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  long ans = S.at(0) - '0' - 1, sub = 0; 
  ans += 9 * (S.size() - 1);
  for(char a: S)sub += S.at(i) - '0';
  cout << max(sub, ans) << endl;
}