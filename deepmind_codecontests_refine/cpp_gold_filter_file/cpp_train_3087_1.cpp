#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string pat = "aeiouy";
  int n;
  cin >> n;
  char p, c;
  cin >> p;
  cout << p;
  while (cin >> c) {
    if (pat.find(c) != string::npos && pat.find(p) != string::npos) continue;
    p = c;
    cout << p;
  }
  cout << endl;
  return 0;
}
