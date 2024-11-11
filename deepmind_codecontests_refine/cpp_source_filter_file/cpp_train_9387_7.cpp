#include <bits/stdc++.h>
using namespace std;
int n;
char buf[1000100];
string s1, s2;
string r1, r2;
int z[2][2000100];
int pre[1000100];
void get_z(int num, string s) {
  int sz = s.size();
  memset(z[num], 0, sizeof(z[num]));
  int l = 0, r = 0;
  for (int i = 1; i < sz; i++) {
    if (i <= r) z[num][i] = min(z[num][i - l], r - i + 1);
    while (i + z[num][i] < sz && s[i + z[num][i]] == s[z[num][i]]) z[num][i]++;
    if (i + z[num][i] > r) {
      r = i + z[num][i];
      l = i;
    }
  }
}
int main() {
  gets(buf);
  s1 = buf;
  gets(buf);
  s2 = buf;
  if (s1.size() != s2.size()) {
    cout << "-1 -1" << endl;
    return 0;
  }
  n = s1.size();
  r1 = s1, r2 = s2;
  reverse(r1.begin(), r1.end());
  reverse(r2.begin(), r2.end());
  int pos = 0;
  while (pos < n && s1[pos] == r2[pos]) pos++;
  get_z(0, s2 + '\n' + s1);
  get_z(1, r1 + '\n' + s2);
  int r = 0;
  memset(pre, -1, sizeof(pre));
  for (int i = 0; i < n; i++) {
    int ind = i + n + 1;
    if (i + z[1][ind] > r) {
      for (int j = max(r, i); j < i + z[1][ind]; j++) pre[j] = j - i + 1;
      r = i + z[1][ind];
    }
  }
  for (int len = min(pos, n - 1); len > 0; len--) {
    int z1 = z[0][len + n + 1], z2 = pre[n - len - 1];
    if (z1 + max(z2, 0) >= n - len) {
      cout << len - 1 << " " << max(n - z2, len) << endl;
      return 0;
    }
  }
  cout << "-1 -1" << endl;
  return 0;
}
