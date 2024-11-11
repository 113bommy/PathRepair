#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool createMat(int a, int b, string &s) {
  int mat[a][b], c = 0;
  for (int i = 0; i < a; i += 1) {
    for (int j = 0; j < b; j += 1) {
      mat[i][j] = (s[c] == 'X') ? 1 : 0;
      c++;
    }
  }
  bool flag;
  for (int j = 0; j < b; j += 1) {
    flag = true;
    for (int i = 0; i < a; i += 1) {
      if (mat[i][j] == 0) {
        flag = false;
        break;
      }
    }
    if (flag == true) return flag;
  }
  return flag;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    int c = 0;
    bool ans[13] = {false};
    cin >> s;
    for (int i = 1; i < 13; i += 1) {
      if (12 % i != 0) continue;
      ans[i] = createMat(i, 12 / i, s);
      if (ans[i]) {
        c++;
      }
    }
    cout << c;
    for (int i = 1; i < 13; i += 1) {
      if (ans[i]) cout << " " << i << "*" << 12 / i;
    }
    cout << "\n";
  }
  return 0;
}
