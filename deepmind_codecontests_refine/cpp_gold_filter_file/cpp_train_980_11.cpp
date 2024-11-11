#include <bits/stdc++.h>
using namespace std;
int P1, P2;
string T1, T2;
int main() {
  cin >> T1;
  cin >> T2;
  for (int i = 0; i < T1.length(); i += 2) {
    if (T1[i] == T2[i]) continue;
    if (T1[i] == '[' && T2[i] == '8') P2++;
    if (T1[i] == '[' && T2[i] == '(') P1++;
    if (T1[i] == '8' && T2[i] == '[') P1++;
    if (T1[i] == '8' && T2[i] == '(') P2++;
    if (T1[i] == '(' && T2[i] == '8') P1++;
    if (T1[i] == '(' && T2[i] == '[') P2++;
  }
  if (P1 == P2)
    cout << "TIE\n";
  else if (P1 < P2)
    cout << "TEAM 2 WINS\n";
  else
    cout << "TEAM 1 WINS\n";
}
