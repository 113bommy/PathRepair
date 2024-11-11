#include <bits/stdc++.h>
using namespace std;
vector<vector<char> > ans;
vector<vector<char> > now;
vector<char> tmp;
int R, c;
int N;
int len[1010000];
int f[21][1010000];
inline int go(int l) {
  int p = R;
  l--;
  for (int i = 20; i >= 0; i--)
    if (p & (1 << i)) {
      l = f[i][l + 1];
      p -= (1 << i);
      if (!l) return N;
    }
  return l;
}
inline void workit() {
  int n = now.size();
  N = n;
  if (!n) return;
  for (int i = (1); i <= (int)n; i++) len[i] = now[i - 1].size();
  for (int i = (1); i <= (int)n; i++) len[i] += len[i - 1];
  for (int i = (1); i <= (int)n; i++) {
    int l = i;
    int r = n;
    int re = 0;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (len[mid] - len[i - 1] + mid - i <= c) {
        re = mid;
        l = mid + 1;
      } else
        r = mid;
    }
    if (len[l] - len[i - 1] + l - i <= c) re = l;
    f[0][i] = re;
  }
  for (int j = (1); j <= (int)20; j++)
    for (int i = (1); i <= (int)n; i++) {
      if (!f[j - 1][i])
        f[j][i] = 0;
      else
        f[j][i] = f[j - 1][f[j][i] + 1];
    }
  int al, ar;
  al = ar = 0;
  ar = -1;
  for (int i = (1); i <= (int)n; i++) {
    int r = go(i);
    if (r - i + 1 >= ar - al + 1) {
      al = i;
      ar = r;
    }
  }
  if (ar - al + 1 > ans.size()) {
    while (ans.size()) ans.pop_back();
    for (int i = (al); i <= (int)ar; i++) ans.push_back(now[i - 1]);
  }
  for (int i = (1); i <= (int)n; i++)
    for (int j = (0); j <= (int)20; j++) f[j][i] = 0;
}
int n;
int main() {
  scanf("%d%d%d", &n, &R, &c);
  for (int i = 1; i <= n; i++) {
    while (tmp.size()) tmp.pop_back();
    char p = getchar();
    while (!(p <= 'z' && p >= 'a')) p = getchar();
    while (p <= 'z' && p >= 'a') tmp.push_back(p), p = getchar();
    if (tmp.size() > c) {
      workit();
      while (now.size()) now.pop_back();
    } else
      now.push_back(tmp);
  }
  workit();
  for (int i = 0; i < ans.size(); i++) {
    int j = i;
    int tot = ans[i].size();
    while (j + 1 < ans.size() && tot + ans[j + 1].size() + 1 <= c) {
      tot += ans[j + 1].size() + 1;
      j++;
    }
    for (int k = (i); k <= (int)j; k++) {
      for (int p = (0); p <= (int)ans[k].size() - 1; p++)
        printf("%c", ans[k][p]);
      if (k != j)
        printf(" ");
      else
        printf("\n");
    }
    i = j;
  }
}
