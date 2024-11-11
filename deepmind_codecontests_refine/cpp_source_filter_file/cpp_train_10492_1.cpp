#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  regex R("(hi)+");
  cout << ((regex_match(S, R)) ? "YES" : "NO") << "\n";
}
