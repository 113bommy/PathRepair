#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
void __never(int a) { printf("\nOPS %d", a); }
int n;
string C[100];
int T[100][100][2];
int P[100];
string ans[100];
int ans_sz = 0;
int F(int x, int y) {
  if (x > y) return 3;
  if (x == y) return 1;
  return 0;
}
bool le(int i, int j) {
  int sumi = 0, sumj = 0;
  for (int a = (1); a <= (n); a++) {
    sumi += F(T[i][a][0], T[i][a][1]);
    sumj += F(T[j][a][0], T[j][a][1]);
  }
  if (sumi != sumj) return sumi > sumj;
  int dei = 0, dej = 0;
  for (int a = (1); a <= (n); a++) {
    dei += T[i][a][0] - T[i][a][1];
    dej += T[j][a][0] - T[j][a][1];
  }
  if (dei != dej) return dei > dej;
  int zai = 0, zaj = 0;
  for (int a = (1); a <= (n); a++) {
    zai += T[i][a][0];
    zaj += T[j][a][0];
  }
  return zai > zaj;
}
void sol() {
  for (int a = (1); a <= (n); a++) P[a] = a;
  sort(P + 1, P + n + 1, le);
  for (int a = (1); a <= (n / 2); a++) ans[ans_sz++] = C[P[a]];
  sort(ans, ans + ans_sz);
  for (int a = (0); a <= (ans_sz - 1); a++) cout << ans[a] << "\n";
}
int main() {
  cin >> n;
  for (int a = (1); a <= (n); a++) cin >> C[a];
  string s1, s2;
  for (int a = (1); a <= ((n * (n - 1)) / 2); a++) {
    cin >> s1 >> s2;
    string c1 = "", c2 = "";
    bool first = true;
    for (int b = (0); b <= ((int)((s1).size()) - 1); b++)
      if (s1[b] == '-')
        first = false;
      else if (first)
        c1.push_back(s1[b]);
      else
        c2.push_back(s1[b]);
    int i, j;
    for (int b = (1); b <= (n); b++)
      if (C[b] == c1) i = b;
    for (int b = (1); b <= (n); b++)
      if (C[b] == c2) j = b;
    int x, y;
    sscanf(s2.c_str(), "%d:%d", &x, &y);
    T[i][j][0] = x;
    T[i][j][1] = y;
    T[j][i][0] = y;
    T[j][i][1] = x;
  }
  sol();
  return 0;
}
