#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[300005], save[300005], ans[300005];
string s;
void Input() {
  cin >> n >> m;
  for (int i = 0; i < (n); ++i) {
    cin >> s;
    for (int j = 0; j < (m); ++j)
      if (s[j] == 'G')
        a[i * m + j] = 1;
      else if (s[j] == 'C')
        a[i * m + j] = 2;
      else if (s[j] == 'T')
        a[i * m + j] = 3;
  }
}
int CalcRow(int i, int A, int B) {
  int res = 0;
  for (int j = 0; j < (m); ++j)
    res += (a[i * m + j] != (save[i * m + j] = (j & 1 ? A : B)));
  return res;
}
int CalcCol(int j, int A, int B) {
  int res = 0;
  for (int i = 0; i < (n); ++i)
    res += (a[i * m + j] != (save[i * m + j] = (i & 1 ? A : B)));
  return res;
}
void Save() {
  for (int i = 0; i < (n * m); ++i) ans[i] = save[i];
}
void Solve() {
  int res = n * m + 1;
  for (int A = 0; A < (4); ++A)
    for (int B = 0; B < (A); ++B) {
      int C, D;
      for (int x = 0; x < (4); ++x)
        if (x != A && x != B) C = x;
      D = 6 - A - B - C;
      int cur = 0;
      for (int i = 0; i < (n); ++i) {
        if (i & 1) {
          int tmp = CalcRow(i, A, B);
          int tmp2 = CalcRow(i, B, A);
          if (tmp >= tmp2)
            cur += tmp2;
          else
            cur += CalcRow(i, A, B);
        } else {
          int tmp = CalcRow(i, C, D);
          int tmp2 = CalcRow(i, D, C);
          if (tmp >= tmp2)
            cur += tmp2;
          else
            cur += CalcRow(i, C, D);
        }
      }
      if (cur < res) res = cur, Save();
      cur = 0;
      for (int i = 0; i < (m); ++i) {
        if (i & 1) {
          int tmp = CalcCol(i, A, B);
          int tmp2 = CalcCol(i, B, A);
          if (tmp >= tmp2)
            cur += tmp2;
          else
            cur += CalcCol(i, A, B);
        } else {
          int tmp = CalcCol(i, C, D);
          int tmp2 = CalcCol(i, D, C);
          if (tmp >= tmp2)
            cur += tmp2;
          else
            cur += CalcCol(i, C, D);
        }
      }
      if (cur < res) res = cur, Save();
    }
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j)
      cout << (ans[i * m + j] ? ans[i * m + j] == 1   ? 'G'
                                : ans[i * m + j] == 2 ? 'C'
                                                      : 'T'
                              : 'A');
    cout << '\n';
  }
  cerr << res << '\n';
}
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  Input();
  Solve();
  return 0;
}
