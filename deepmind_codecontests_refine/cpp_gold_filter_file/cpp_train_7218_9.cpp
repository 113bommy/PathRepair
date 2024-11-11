#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 3;
char ch;
bool flag = 0;
void read(int &x) {
  for (ch = getchar(); !isdigit(ch) && ((flag |= (ch == '-')) || 1);
       ch = getchar())
    ;
  for (x = 0; isdigit(ch); x = (x << 1) + (x << 3) + ch - 48, ch = getchar())
    ;
  x *= 1 - 2 * flag;
}
string ans = "";
bool h = 0;
string s;
void fu() {
  if (cin >> s) {
    ans += s;
    if (s == "pair") {
      ans += "<";
      fu();
      ans += ",";
      fu();
      ans += ">";
    }
  } else {
    h = 1;
  }
  if (h) return;
}
int main() {
  int n;
  read(n);
  fu();
  if (h || (cin >> s))
    cout << "Error occurred" << endl;
  else
    cout << ans << endl;
  return 0;
}
