#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535;
const double eps = 1e-6;
string kong = "";
int f[100000][2], win[100000], suan[100000];
void update(int &a, int &b, int &c, int A, int B, int C) {
  if (A > a || A == a && B > b || A == a && B == b && C < c) {
    a = A, b = B, c = C;
  }
}
vector<string> rec;
int index(string a) {
  return lower_bound(rec.begin(), rec.end(), a) - rec.begin();
}
void dfs(int a) {
  if (win[a] != -1) return;
  int won = 0, fir = 0, sec = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    int nu = index(kong + rec[a] + c);
    if (rec[nu] == kong + rec[a] + c) {
      dfs(nu);
      update(won, fir, sec, win[nu] ^ 1, f[nu][1] + suan[nu], f[nu][0]);
    }
    nu = index(kong + c + rec[a]);
    if (rec[nu] == kong + c + rec[a]) {
      dfs(nu);
      update(won, fir, sec, win[nu] ^ 1, f[nu][1] + suan[nu], f[nu][0]);
    }
  }
  f[a][0] = fir, f[a][1] = sec, win[a] = won;
}
int n;
string s, whi[100], S;
int main() {
  cin >> n;
  rec.push_back("");
  rec.push_back("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
  for (int i = 0; i < n; i++) {
    cin >> s;
    whi[i] = s;
    for (int j = 0; j < s.size(); j++) {
      S = "";
      for (int k = j; k < s.size(); k++) {
        S += s[k];
        rec.push_back(S);
      }
    }
  }
  memset(win, -1, sizeof(win));
  sort(rec.begin(), rec.end());
  rec.erase(unique(rec.begin(), rec.end()), rec.end());
  for (int i = 0; i < rec.size(); i++) {
    int ap = 0;
    for (int j = 0; j < n; j++)
      if (whi[j].find(rec[i]) != -1) ap++;
    int su = 0, ma = 0;
    for (int j = 0; j < rec[i].size(); j++) {
      su += rec[i][j] - 'a' + 1;
      ma = max(ma, rec[i][j] - 'a' + 1);
    }
    suan[i] = ma * su + ap;
  }
  dfs(index(""));
  if (win[index("")])
    puts("First");
  else
    puts("Second");
  printf("%d %d\n", f[index("")][0], f[index("")][1]);
}
