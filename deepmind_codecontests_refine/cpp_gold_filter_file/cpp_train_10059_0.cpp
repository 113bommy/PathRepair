#include <bits/stdc++.h>
using namespace std;
string s;
int n;
vector<int> va, vb;
int vv(int l, int r) { return va[l] + vb[r] - vb[l] + va[n] - va[r]; }
int main() {
  cin >> s;
  int i, j;
  n = s.size();
  va.resize(n + 1);
  vb.resize(n + 1);
  for (i = 1; i <= n; i++) va[i] = va[i - 1] + (s[i - 1] == 'a' ? 1 : 0);
  for (i = 1; i <= n; i++) vb[i] = vb[i - 1] + (s[i - 1] == 'b' ? 1 : 0);
  int an = 0;
  for (i = 0; i <= n; i++) {
    for (j = i; j <= n; j++) {
      an = max(vv(i, j), an);
    }
  }
  cout << an;
}
