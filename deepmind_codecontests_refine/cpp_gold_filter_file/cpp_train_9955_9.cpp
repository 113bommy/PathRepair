#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const long long md = 1e9 + 7;
int main() {
  iostream::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  vector<int> cn(5, 0);
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s.substr(i, min((int)s.length() - i, 5)) == "Danil") cn[0]++;
    if (s.substr(i, min((int)s.length() - i, 4)) == "Olya") cn[1]++;
    if (s.substr(i, min((int)s.length() - i, 5)) == "Slava") cn[2]++;
    if (s.substr(i, min((int)s.length() - i, 3)) == "Ann") cn[3]++;
    if (s.substr(i, min((int)s.length() - i, 6)) == "Nikita") cn[4]++;
  }
  bool ch = 1;
  int C = 0;
  for (int i = 0; i < 5; i++) {
    if (cn[i] > 1) ch = 0;
    if (cn[i]) C++;
  }
  if (ch && C == 1)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
