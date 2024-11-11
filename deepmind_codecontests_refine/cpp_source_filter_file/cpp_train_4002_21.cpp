#include <bits/stdc++.h>
using namespace std;
int testCase;
string s;
int iinf = 1e9 + 1;
long long inf = 1e16 + 1;
void solve() {
  cin >> s;
  bool a = false, b = false, c = false, d = false;
  if (s.length() > 5) a = true;
  for (auto i : s) {
    if (i >= 'a' and i <= 'z') b = true;
    if (i >= 'A' and i <= 'Z') c = true;
    if (i >= '0' and i <= '9') d = true;
  }
  if (a and b and c and d)
    cout << "Correct";
  else
    cout << "Too weak";
}
int main() {
  testCase = 1;
  while (testCase--) {
    solve();
  };
}
