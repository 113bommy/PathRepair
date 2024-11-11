#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, s1;
  int c = 0;
  cin >> s >> s1;
  size_t f = s.find(s1);
  while (f != string::npos) {
    c++;
    f = s.find(s1, f + 1);
  }
  cout << c;
  return 0;
}
