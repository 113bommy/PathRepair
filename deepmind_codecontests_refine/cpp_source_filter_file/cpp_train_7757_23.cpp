#include <bits/stdc++.h>
using namespace std;
const int N = 2020;
const int Mod = 1e9 + 7;
void add_self(int& x, int y) {
  if ((x += y) >= Mod) x -= Mod;
}
int n, m;
string s;
int Dp[N][N][2];
int ExtraL, ExtraR;
int Rec(int k = n - m, int Open = 0, bool Taken = false) {
  if (k < 0) return 0;
  if (Open < 0) return 0;
  if (Open > k) return 0;
  if (!k && Taken) return !Open;
  if (Dp[k][Open][Taken] + 1) return Dp[k][Open][Taken];
  int Res = 0;
  add_self(Res, Rec(k - 1, Open + 1, Taken));
  add_self(Res, Rec(k - 1, Open - 1, Taken));
  if (!Taken && Open >= ExtraR)
    add_self(Res, Rec(k, Open - ExtraR + ExtraL, true));
  return Dp[k][Open][Taken] = Res;
}
int main() {
  cin >> n >> m >> s;
  for (char c : s) {
    if (c == '(')
      ExtraL++;
    else if (ExtraL)
      ExtraL--;
    else
      ExtraR++;
  }
  memset(Dp, -1, sizeof(Dp));
  cout << Rec() << endl;
}
