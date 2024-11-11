#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string code;
  map<string, char> mopp;
  cin >> code;
  string s;
  for (int i = 0; i < 10; i++) {
    char x = i + '0';
    string z;
    cin >> z;
    mopp[z] = x;
  }
  string fin = "";
  int hold = 0;
  for (int i = 0; i < code.size() + 1; i += 10) {
    fin += mopp[code.substr(i, 10)];
    hold += 10;
  }
  cout << fin;
  return 0;
  ;
}
