#include <bits/stdc++.h>
using namespace std;
char b[9];
struct tm t = {0};
string m(int i) {
  if (i == 8) return "September";
  t.tm_mon = i;
  strftime(b, sizeof(b), "%B", &t);
  return b;
}
int main() {
  int k;
  string s;
  cin >> s >> k;
  for (int i = 0; i < 12; i++)
    if (m(i) == s) cout << m((i + k) % 12);
}
