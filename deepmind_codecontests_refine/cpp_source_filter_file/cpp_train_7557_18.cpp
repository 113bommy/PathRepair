#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int h[27];
int flag[maxn];
int main() {
  fill(h, h + 27, 0);
  fill(flag, flag + maxn, 0);
  string s1;
  cin >> s1;
  for (int i = 0; i < s1.size(); i++)
    if (s1[i] >= 'a' && s1[i] <= 'z') h[s1[i] - 'a' + 1] = 1;
  string tmp;
  cin >> tmp;
  int len = tmp.size();
  int have = 0;
  for (int i = 0; i < tmp.size(); i++) {
    if (tmp[i] == '?') flag[i] = 1;
    if (tmp[i] == '*') {
      flag[i] = 2;
      have = 1;
    };
  }
  int n;
  cin >> n;
  while (n--) {
    int is = 0;
    string tmp2;
    cin >> tmp2;
    int t = 0;
    int dis = tmp2.size() - tmp.size();
    if (!have) {
      if (dis > 0) is = 1;
    }
    for (int i = 0; i < tmp2.size(); i++, t++) {
      if (tmp2.size() < len - 1) {
        is = 1;
        break;
      }
      if (flag[t] == 0) {
        if (tmp2[i] - 'a' != tmp[t] - 'a') {
          is = 1;
          break;
        }
      }
      if (flag[t] == 1) {
        if (h[tmp2[i] - 'a' + 1] != 1) {
          is = 1;
          break;
        }
      }
      if (flag[t] == 2) {
        if (dis >= 0) {
          dis++;
          while (dis--) {
            if (h[tmp2[i] - 'a' + 1]) {
              is = 1;
              break;
            }
            i++;
          }
          i--;
        } else
          i--;
      }
    }
    if (is)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
