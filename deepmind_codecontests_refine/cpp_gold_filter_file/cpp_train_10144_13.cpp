#include <bits/stdc++.h>
using namespace std;
int getint() {
  unsigned int c;
  int x = 0;
  while (((c = getchar()) - '0') >= 10) {
    if (c == '-') return -getint();
    if (!~c) exit(0);
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while (((c = getchar()) - '0') < 10);
  return x;
}
int n, m, in[333][333], t;
int flat, asce, desc;
int goL[301][301][301];
int goR[301][301][301];
int main() {
  int i, j, tcc, tc = 1 << 28;
  for (tcc = 0; tcc < tc; tcc++) {
    n = getint(), m = getint(), t = getint();
    flat = getint(), asce = getint(), desc = getint();
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) in[i][j] = getint();
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) {
        int acc = 0;
        for (int len = 0;; len++) {
          int nxt = j + len + 1;
          int bef = j + len;
          if (nxt >= m) break;
          if (in[i][nxt] == in[i][bef]) acc += flat;
          if (in[i][nxt] > in[i][bef]) acc += asce;
          if (in[i][nxt] < in[i][bef]) acc += desc;
          goR[i][j][len + 1] = acc;
        }
        acc = 0;
        for (int len = 0;; len++) {
          int nxt = j - len - 1;
          int bef = j - len;
          if (nxt < 0) break;
          if (in[i][nxt] == in[i][bef]) acc += flat;
          if (in[i][nxt] > in[i][bef]) acc += asce;
          if (in[i][nxt] < in[i][bef]) acc += desc;
          goL[i][j][len + 1] = acc;
        }
      }
    int res = 1300000000;
    vector<int> resXY(4);
    for (int leftL = 0; leftL < m; leftL++)
      for (int rightL = leftL + 2; rightL < m; rightL++) {
        const int LRlen = rightL - leftL;
        vector<int> costV(n);
        int acc = 0;
        for (i = 1; i < n; i++) {
          if (in[i][leftL] == in[i - 1][leftL]) acc += flat;
          if (in[i][leftL] > in[i - 1][leftL]) acc += desc;
          if (in[i][leftL] < in[i - 1][leftL]) acc += asce;
          if (in[i][rightL] == in[i - 1][rightL]) acc += flat;
          if (in[i][rightL] < in[i - 1][rightL]) acc += desc;
          if (in[i][rightL] > in[i - 1][rightL]) acc += asce;
          costV[i] = acc;
        }
        set<pair<int, int> > costSet;
        set<pair<int, int> >::iterator it;
        for (i = n - 1; i - 2 >= 0; --i) {
          const int cost = goL[i][rightL][LRlen] + costV[i];
          costSet.insert(make_pair(cost, i));
          int upCost = goR[i - 2][leftL][LRlen] - costV[i - 2];
          int rem = t - upCost;
          it = costSet.lower_bound(make_pair(rem, -1));
          if (it != costSet.end()) {
            int a = it->first;
            int x = it->second;
            if (res > a - rem) {
              res = a - rem;
              resXY[0] = i - 2;
              resXY[1] = leftL;
              resXY[2] = x;
              resXY[3] = rightL;
            }
          }
          if (it != costSet.begin()) {
            it--;
            int a = it->first;
            int x = it->second;
            if (res > rem - a) {
              res = rem - a;
              resXY[0] = i - 2;
              resXY[1] = leftL;
              resXY[2] = x;
              resXY[3] = rightL;
            }
          }
        }
      }
    cerr << res << endl;
    for (i = 0; i < resXY.size(); i++) cout << resXY[i] + 1 << ' ';
    puts("");
  }
  return 0;
}
