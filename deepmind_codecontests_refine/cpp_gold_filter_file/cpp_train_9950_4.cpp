#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
string a, b, c;
bool vis[250];
int pre[maxn], suf[maxn];
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(false);
  cin >> a >> b;
  c = a;
  reverse(c.begin(), c.end());
  bool flag = 0;
  for (int i = 0; i < a.length(); i++) {
    vis[a[i]] = 1;
  }
  for (int i = 0; i < b.length(); i++) {
    if (vis[b[i]]) {
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    cout << '-' << endl;
    return 0;
  }
  int bl = b.length();
  memset(pre, -1, sizeof(pre));
  memset(suf, -1, sizeof(suf));
  for (int i = 1; i <= bl; i++) {
    pre[i] = a.find(b[i - 1], pre[i - 1] + 1);
    if (pre[i] == -1) break;
  }
  for (int i = bl; i > 0; i--) {
    suf[i] = c.find(b[i - 1], suf[i + 1] + 1);
    if (suf[i] == -1) break;
  }
  if (pre[1] == suf[bl] && pre[1] == -1) {
    cout << '-' << endl;
    return 0;
  }
  int fh, ft, l = 0, r = bl, mid, al = a.length();
  while (l <= r) {
    mid = (r + l) >> 1;
    bool flag = 0;
    for (int i = 0; i <= bl - mid; i++) {
      if ((i == 0 || pre[i] != -1) &&
          (i + mid + 1 == bl + 1 || suf[i + mid + 1] != -1) &&
          pre[i] < al - suf[i + mid + 1] - 1) {
        flag = 1;
        fh = i, ft = i + mid + 1;
        break;
      }
    }
    if (flag) {
      r = mid - 1;
    } else
      l = mid + 1;
  }
  string out;
  out = b.substr(0, fh) + b.substr(ft - 1, bl - ft + 1);
  cout << out << endl;
  return 0;
}
