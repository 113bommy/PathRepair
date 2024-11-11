#include <bits/stdc++.h>
using namespace std;
int dp3[305];
int recur3(int a) {
  if (dp3[a] != -2) return dp3[a];
  int res = -1;
  for (int i = 1; i <= 300; i++) {
    if (a >= i) res = max(res, -recur3(a - i));
  }
  dp3[a] = res;
  return res;
}
int dp2[305][305];
int recur2(int a, int b) {
  if (dp2[a][b] != -2) return dp2[a][b];
  int res = -1;
  for (int i = 1; i <= 300; i++) {
    if (a >= i) res = max(res, -recur2(a - i, b));
    if (b >= i) res = max(res, -recur2(a, b - i));
    if (a >= i && b >= i) res = max(res, -recur2(a - i, b - i));
  }
  dp2[a][b] = res;
  return res;
}
int recur1(int a, int b, int c) {
  if (a ^ b ^ c == 0)
    return 1;
  else
    return -1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 305; i++)
    for (int j = 0; j < 305; j++) dp2[i][j] = -2;
  for (int i = 0; i < 305; i++) dp3[i] = -2;
  int n;
  cin >> n;
  if (n == 3) {
    int a, b, c;
    cin >> a >> b >> c;
    int res = recur1(a, b, c);
    if (res == 1)
      cout << "BitLGM\n";
    else
      cout << "BitAryo\n";
  }
  if (n == 2) {
    int a, b;
    cin >> a >> b;
    int res = recur2(a, b);
    if (res == 1)
      cout << "BitLGM\n";
    else
      cout << "BitAryo\n";
  }
  if (n == 1) {
    int a;
    cin >> a;
    int res = recur3(a);
    if (res == 1)
      cout << "BitLGM\n";
    else
      cout << "BitAryo\n";
  }
}
