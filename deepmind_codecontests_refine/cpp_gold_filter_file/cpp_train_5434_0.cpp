#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 200;
string s;
vector<int> zuo, you;
int main() {
  int n;
  cin >> n;
  cin >> s;
  int ff = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '(')
      ff++, zuo.push_back(i);
    else
      ff--, you.push_back(i);
  if (ff) {
    printf("0\n");
    printf("1 1\n");
    return 0;
  }
  int ans = 0, p = 0, w = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '(')
      p++;
    else {
      p--;
      if (p == w)
        ans++;
      else if (p < w) {
        w = p;
        ans = 1;
      }
    }
  int k1 = 1, k2 = 1;
  for (auto i : zuo) {
    for (auto j : you) {
      swap(s[i], s[j]);
      int cur = 0, p = 0, w = 0;
      for (int i = 0; i < n; i++)
        if (s[i] == '(')
          p++;
        else {
          p--;
          if (p == w)
            cur++;
          else if (p < w) {
            w = p;
            cur = 1;
          }
        }
      swap(s[i], s[j]);
      if (cur > ans) {
        ans = cur;
        k1 = i + 1;
        k2 = j + 1;
      }
    }
  }
  printf("%d\n", ans);
  printf("%d %d\n", k1, k2);
}
