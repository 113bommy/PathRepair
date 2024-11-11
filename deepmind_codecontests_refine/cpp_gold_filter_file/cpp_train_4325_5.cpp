#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 100;
char s[maxn];
int len;
int f[maxn];
map<string, int> mp;
vector<string> vec;
int calcu(int a, int b, int c, int d) {
  for (int i = 0;; i++) {
    int t1 = a + i;
    if (t1 > b) {
      break;
    }
    int t2 = c + i;
    if (s[t1] != s[t2]) return 1;
  }
  return 0;
}
void solve() {
  memset(f, 0, sizeof(f));
  f[len] = 1;
  f[len - 1] = 0;
  f[len - 2] = 1;
  f[len - 3] = 1;
  f[len - 4] = 0;
  if (calcu(len - 4, len - 3, len - 2, len - 1)) {
    f[len - 4] = 1;
  }
  f[len - 5] = 1;
  for (int i = len - 6; i >= 5; i--) {
    int j = i + 2;
    if (calcu(i, i + 1, i + 2, i + 3)) {
      f[i] |= f[i + 4];
    }
    f[i] |= f[i + 5];
    if (calcu(i, i + 2, i + 3, i + 5)) {
      f[i] |= f[i + 6];
    }
    f[i] |= f[i + 5];
  }
  mp.clear();
  vec.clear();
  for (int i = 5; i <= len - 2; i++) {
    if (f[i + 2]) {
      string t = "";
      t += s[i];
      t += s[i + 1];
      if (mp[t] == 0) {
        mp[t] = 1;
        vec.push_back(t);
      }
    }
    if (f[i + 3]) {
      string t = "";
      t += s[i];
      t += s[i + 1];
      t += s[i + 2];
      if (mp[t] == 0) {
        mp[t] = 1;
        vec.push_back(t);
      }
    }
  }
  sort(vec.begin(), vec.end());
  printf("%d\n", (int)vec.size());
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << endl;
  }
}
int main() {
  while (scanf("%s", s) != EOF) {
    len = strlen(s);
    solve();
  }
  return 0;
}
