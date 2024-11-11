#include <bits/stdc++.h>
using namespace std;
long long OO = 1e18;
long long Mod = 1e9 + 7;
long long const N = 6e5 + 10;
int a[N];
int main() {
  int n;
  string s;
  cin >> n >> s;
  s = s + s;
  int c = 0, mn = 0, cmn = 0;
  for (int i = 0; i < s.size(); i++) {
    c += s[i] == '(' ? 1 : -1;
    a[i] = c;
    if (c < mn) cmn = 0;
    mn = min(mn, c);
    if (c == mn) cmn++;
  }
  if (c != 0) return cout << "0\n1 1\n", 0;
  int ls = -1, cm_1 = 0, Ans = cmn / 2;
  pair<int, int> Best = {1, 1};
  for (int i = 0; i < s.size(); i++) {
    if (ls == -1) {
      if (a[i] == mn) ls = i;
      cm_1 = 0;
      continue;
    }
    if (a[i] == mn) {
      Ans = max(Ans, cm_1);
      if (Ans == cm_1) {
        Best = {(ls + 1) % n, i % n};
      }
      ls = i;
      cm_1 = 0;
    }
    if (a[i] == mn + 1) cm_1++;
  }
  int cm_2 = 0;
  ls = -1;
  for (int i = 0; i < s.size(); i++) {
    if (ls == -1) {
      if (a[i] == mn + 1) ls = i;
      cm_2 = 0;
      continue;
    }
    if (a[i] == mn + 1) {
      Ans = max(Ans, cmn / 2 + cm_2);
      if (Ans == cmn / 2 + cm_2) {
        Best = {(ls + 1) % n, i % n};
      }
      cm_2 = 0;
      ls = i;
    }
    if (a[i] == mn + 2) cm_2++;
    if (a[i] == mn) ls = -1, cm_2 = 0;
  }
  cout << Ans << endl;
  cout << Best.first + 1 << " " << Best.second + 1 << endl;
}
