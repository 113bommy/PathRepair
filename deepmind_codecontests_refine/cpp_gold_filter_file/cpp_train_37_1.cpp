#include <bits/stdc++.h>
using namespace std;
int in[1000010];
int lc[1000010][21];
int vl[1000010][21];
int n;
string sss[1000010];
int main() {
  int lin, cc;
  cin >> n >> lin >> cc;
  for (int i = (0); i < int(n); i += 1) {
    cin >> sss[i];
    in[i] = sss[i].size();
    if (i) in[i] += in[i - 1];
  }
  for (int i = (n - 1); i > int(0 - 1); i -= 1) {
    int s = i, e = n - 1, last = i - 1, mid;
    while (s <= e) {
      mid = (s + e) >> 1;
      int val = in[mid];
      if (i) val -= in[i - 1];
      val += mid - i;
      if (val > cc)
        e = mid - 1;
      else
        s = mid + 1, last = mid;
    }
    e = last;
    lc[i][0] = e + 1;
    if (e < i) lc[i][0] = -1;
    vl[i][0] = e - i + 1;
  }
  for (int i = (n - 1); i > int(0 - 1); i -= 1)
    for (int j = (1); j < int(21); j += 1) {
      if (lc[i][j - 1] < n && lc[i][j - 1] != -1)
        lc[i][j] = lc[lc[i][j - 1]][j - 1],
        vl[i][j] = vl[i][j - 1] + vl[lc[i][j - 1]][j - 1];
      else
        lc[i][j] = -1;
    }
  pair<int, int> ans = make_pair(-1, 0);
  for (int i = (0); i < int(n); i += 1) {
    int on = i;
    int to = lin;
    int jam = 0;
    for (int j = (20); j > int(0 - 1); j -= 1) {
      if (lc[on][j] == -1) continue;
      if ((1 << j) > to) continue;
      to -= 1 << j;
      jam += vl[on][j];
      on = lc[on][j];
    }
    ans = max(ans, make_pair(jam, i));
  }
  if (ans.first > 0) {
    int su = -1;
    for (int i = (ans.second); i < int(ans.first + ans.second); i += 1) {
      if (su + sss[i].size() + 1 > cc) putchar('\n'), su = -1;
      if (su != -1) putchar(' ');
      su += sss[i].size() + 1;
      printf("%s", sss[i].c_str());
    }
  }
  return 0;
}
