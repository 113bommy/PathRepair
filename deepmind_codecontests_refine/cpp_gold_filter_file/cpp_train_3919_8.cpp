#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAX = 300009;
char col[MAX];
int pos[MAX];
int main() {
  int n;
  scanf("%d", &n);
  map<char, int> mmin, mmax;
  for (int i = 0; i < n; i++) {
    scanf("%d %c", pos + i, col + i);
    if (!mmin.count(col[i])) mmin[col[i]] = pos[i];
    mmax[col[i]] = pos[i];
  }
  long long ans = 0;
  if (!mmin.count('G')) {
    for (char c : "RB")
      if (mmin.count(c)) ans += mmax[c] - mmin[c];
    cout << ans << endl;
    return 0;
  }
  for (char c : "RB") {
    if (mmin.count(c) && mmin['G'] > mmin[c]) ans += mmin['G'] - mmin[c];
    if (mmax.count(c) && mmax['G'] < mmax[c]) ans += mmax[c] - mmax['G'];
  }
  int i = 0;
  while (pos[i] < mmin['G']) i++;
  int gst = pos[i];
  int bcr = gst;
  int rcr = gst;
  int bmx = 0;
  int rmx = 0;
  for (++i; pos[i] <= mmax['G']; i++) {
    if (col[i] != 'B') {
      rmx = max(rmx, pos[i] - rcr);
      rcr = pos[i];
    }
    if (col[i] != 'R') {
      bmx = max(bmx, pos[i] - bcr);
      bcr = pos[i];
    }
    if (col[i] == 'G') {
      long long dif = pos[i] - gst;
      ans += min(3 * dif - bmx - rmx, 2 * dif);
      bmx = 0;
      rmx = 0;
      gst = pos[i];
    }
  }
  cout << ans << endl;
}
