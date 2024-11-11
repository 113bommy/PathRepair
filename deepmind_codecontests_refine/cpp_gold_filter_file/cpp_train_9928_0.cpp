#include <bits/stdc++.h>
using namespace std;
string str = "000000000";
int q = 0;
int n;
int u;
set<int> y;
void bust(int x) {
  if (x == u) {
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++) {
        string r = "";
        for (int k = 0; k < u; k++)
          if (str[k] == '0') {
            r += i + '0';
          } else
            r += j + '0';
        if (atoi(r.c_str()) <= n && y.find(atoi(r.c_str())) == y.end()) {
          q++;
          y.insert(atoi(r.c_str()));
        }
      }
    return;
  }
  str[x] = '0';
  bust(x + 1);
  str[x] = '1';
  bust(x + 1);
}
int main() {
  cin >> n;
  for (u = 1; u < 10; u++) {
    str[0] = '1';
    bust(1);
  }
  if (n == 1000000000) q++;
  cout << q - 1;
  return 0;
}
