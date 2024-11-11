#include <bits/stdc++.h>
using namespace std;
long long int n, m, i, j, k, l, T, u, v, q, t = 0, t1 = 0, te, c = 0;
long long int a[1010], b[1010];
int main() {
  std::ios::sync_with_stdio(false);
  string s[8];
  for (int i = 0; i < 8; i++) {
    getline(cin, s[i]);
  }
  int ansa = 10, ansb = 10;
  for (int i = 0; i < 8; i++) {
    int g = 10;
    for (int j = 0; j < 8; j++) {
      if (s[j][i] == 'B') {
        g = 10;
        break;
      } else if (s[j][i] == 'W') {
        g = j;
        break;
      }
    }
    ansa = min(ansa, g);
  }
  for (int i = 0; i < 8; i++) {
    int g = 10;
    for (int j = 7; j >= 0; j--) {
      if (s[j][i] == 'W') {
        g = 10;
        break;
      } else if (s[j][i] == 'B') {
        g = j;
        break;
      }
    }
    ansb = min(ansb, g);
  }
  if (ansa <= ansb)
    cout << "A" << endl;
  else
    cout << "B" << endl;
}
