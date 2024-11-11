#include <bits/stdc++.h>
FILE *in = stdin, *out = stdout;
using namespace std;
int n, c;
vector<int> a[200005 * 3];
void input() {
  fscanf(in, "%d", &n), fscanf(in, "%d", &c);
  for (int i = (1); i <= (n); i++) {
    int x;
    fscanf(in, "%d", &x);
    for (int j = (1); j <= (x); j++) {
      int y;
      fscanf(in, "%d", &y);
      a[i].push_back(y);
    }
  }
}
int cnt[1000005];
void pro() {
  for (int i = (1); i <= (n - 1); i++) {
    int flag = 0;
    for (int j = 0; j < a[i].size(); j++) {
      if (j >= a[i + 1].size()) {
        fprintf(out, "-1");
        return;
      }
      if (a[i][j] > a[i + 1][j]) {
        int L = c + 1 - a[i][j];
        int R = c - a[i + 1][j];
        cnt[L]++;
        cnt[R + 1]--;
        flag = 1;
        break;
      } else if (a[i][j] < a[i + 1][j]) {
        int L = 0;
        int R = c - a[i + 1][j];
        cnt[L]++;
        cnt[R + 1]--;
        L = c + 1 - a[i][j];
        R = c - 1;
        if (L < c) cnt[L]++;
        cnt[R + 1]--;
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cnt[0]++, cnt[c]--;
    }
  }
  int res = 0;
  for (int i = (0); i <= (c - 1); i++) {
    res += cnt[i];
    if (res == n - 1) {
      fprintf(out, "%d", i);
      return;
    }
  }
  fprintf(out, "-1");
}
int main() {
  input();
  pro();
  return 0;
}
