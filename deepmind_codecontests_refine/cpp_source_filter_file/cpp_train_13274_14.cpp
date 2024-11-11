#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
char d[1000][1000];
char rev(char a) {
  if (a == '*') return '+';
  return '*';
}
int main() {
  int n;
  cin >> n;
  d[0][0] = '+';
  for (int i = 0; i < n; i++) {
    for (int x = 0; x < (1 << i); x++) {
      for (int y = 0; y < (1 << i); y++) {
        int t = 1 << i;
        d[x + t][y] = d[x][y + t] = d[x][y];
        d[x + t][y + t] = rev(d[x][y]);
      }
    }
  }
  for (int x = 0; x <= (1 << n); x++) {
    for (int y = 0; y <= (1 << n); y++) {
      cout << d[x][y];
    }
    cout << endl;
  }
  return 0;
}
