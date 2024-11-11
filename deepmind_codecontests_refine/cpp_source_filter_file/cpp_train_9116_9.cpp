#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
int n, m, ans[maxn], ans2[maxn], op[maxn], a[maxn][2], c[maxn];
string na[maxn], val[maxn];
map<string, int> mp;
int get(int k, int o) {
  for (int i = 1; i <= n; i++) {
    if (!op[i])
      c[i] = val[i][k] - '0';
    else {
      int x1 = a[i][0], x2 = a[i][1];
      if (x1 == -1)
        x1 = o;
      else
        x1 = c[x1];
      if (x2 == -1)
        x2 = o;
      else
        x2 = c[x2];
      if (op[i] == 1) c[i] = x1 & x2;
      if (op[i] == 2) c[i] == x1 | x2;
      if (op[i] == 3) c[i] = x1 ^ x2;
    }
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) ret += c[i];
  return ret;
}
int main() {
  string fuck("?");
  mp[fuck] = -1;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> na[i];
    string temp;
    cin >> temp;
    cin >> temp;
    if (temp[0] == '0' || temp[0] == '1')
      val[i] = temp;
    else {
      a[i][0] = mp[temp];
      cin >> temp;
      if (temp[0] == 'A') op[i] = 1;
      if (temp[0] == 'O') op[i] = 2;
      if (temp[0] == 'X') op[i] = 3;
      cin >> temp;
      a[i][1] = mp[temp];
    }
    mp[na[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    int s = get(i, 0), s1 = get(i, 1);
    if (s == s1)
      ans[i] = ans2[i] = 0;
    else if (s < s1) {
      ans[i] = 0;
      ans2[i] = 1;
    } else {
      ans[i] = 1;
      ans2[i] = 0;
    }
  }
  for (int i = 0; i < m; i++) printf("%d", ans[i]);
  cout << endl;
  for (int i = 0; i < m; i++) printf("%d", ans2[i]);
  return 0;
}
