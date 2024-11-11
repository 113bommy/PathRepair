#include <bits/stdc++.h>
using namespace std;
int b[50];
int c[50];
int change(string s) {
  if (s == "a") return 1;
  if (s == "b") return 2;
  if (s == "c") return 3;
  if (s == "d") return 4;
  if (s == "e") return 5;
  if (s == "f") return 6;
  if (s == "g") return 7;
  if (s == "h") return 8;
  if (s == "i") return 9;
  if (s == "k") return 10;
  if (s == "j") return 11;
  if (s == "l") return 12;
  if (s == "m") return 13;
  if (s == "n") return 14;
  if (s == "o") return 15;
  if (s == "p") return 16;
  if (s == "q") return 17;
  if (s == "r") return 18;
  if (s == "s") return 19;
  if (s == "t") return 20;
  if (s == "u") return 21;
  if (s == "v") return 22;
  if (s == "w") return 23;
  if (s == "x") return 24;
  if (s == "y") return 25;
  if (s == "z") return 26;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string stringg;
    cin >> stringg;
    int f = 0;
    for (int i = 0; i < stringg.size(); i++) {
      string k;
      k = stringg.substr(i, 1);
      f++;
      b[f] = change(k);
    }
    for (int i = 1; i <= n; i++) {
      c[i] = b[i];
    }
    sort(c + 1, c + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (b[i] != c[i]) cnt++;
    }
    cout << cnt << endl;
    memset(b, 127, sizeof(b));
    memset(c, 127, sizeof(c));
  }
}
