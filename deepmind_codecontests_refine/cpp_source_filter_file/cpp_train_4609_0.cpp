#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int L = 1000005;
const int mo = 1000000007;
int n, l[N];
vector<int> f[N];
string s[N];
char s1[L], s2[L];
int f1[L], f2[L], lcp[L];
void UPD(int &x, int y) { (x += y) >= mo ? x -= mo : 233; }
void DIAO(int x) {
  int mx = max(l[x], l[x - 1]) + 2;
  for (int i = (int)(0); i <= (int)(mx + 2); i++) {
    s1[i] = s2[i] = 'a' - 1;
    f1[i] = f2[i] = lcp[i] = 0;
  }
  for (int i = (int)(0); i <= (int)(l[x - 1]); i++) f1[i] = f[x - 1][i];
  for (int i = (int)(0); i <= (int)(l[x - 1] - 1); i++) s1[i] = s[x - 1][i];
  for (int i = (int)(0); i <= (int)(l[x] - 1); i++) s2[i] = s[x][i];
  for (int i = (int)(mx + 1); i >= (int)(0); i--)
    lcp[i] = (s1[i] == s2[i] ? lcp[i + 1] + 1 : 0);
  int v1 = 0, v2 = 0, fl = 0;
  for (int i = (int)(0); i <= (int)(mx); i++) {
    if (i) {
      if (s1[i] < s2[i - 1]) v2 += v1, v1 = 0;
      if (s1[i] > s2[i - 1]) v1 = 0;
    }
    if (fl == 0) UPD(v1, f1[i]);
    if (fl == 1) UPD(v2, f1[i]);
    if (!fl && s1[i] != s2[i]) fl = (s1[i] < s2[i] ? 1 : -1);
    f2[i] = v2;
    int p = i + 1 + lcp[i + 1];
    if (p > mx || s1[p] < s2[p]) UPD(f2[i], v1);
  }
  v1 = v2 = 0;
  for (int i = (int)(mx); i >= (int)(0); i--) {
    int p = lcp[0];
    if (p >= i)
      UPD(f2[i], v1);
    else if (s1[p] < s2[p]) {
      UPD(f2[i], v1);
      UPD(f2[i], v2);
    }
    p = i + 1 + lcp[i + 1];
    if (p > mx || s1[p] < s2[p])
      UPD(v1, f1[i]);
    else
      UPD(v2, f1[i]);
    if (s1[i - 1] < s2[i]) UPD(v1, v2), v2 = 0;
    if (s1[i - 1] > s2[i]) UPD(v2, v1), v1 = 0;
  }
  for (int i = (int)(0); i <= (int)(l[x]); i++) {
    f[x][i] = f2[i];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) cin >> s[i];
  for (int i = (int)(1); i <= (int)(n); i++) l[i] = s[i].length();
  for (int i = (int)(1); i <= (int)(n); i++) f[i].resize(l[i] + 1);
  for (int i = (int)(0); i <= (int)(l[1]); i++) f[1][i] = 1;
  for (int i = (int)(2); i <= (int)(n); i++) DIAO(i);
  int ans = 0;
  for (int i = (int)(0); i <= (int)(l[n]); i++) UPD(ans, f[n][i]);
  cout << ans << endl;
}
