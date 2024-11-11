#include <bits/stdc++.h>
using namespace std;
string kip[100005];
int rec[100005], a[100005];
char s[100005];
map<string, int> mm;
string cur;
int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline bool chk(int id) {
  int flag, i, d1, m1, y1;
  flag = true;
  cur.clear();
  for (i = id; i < id + 10; i++) {
    if (i == (id + 2) || i == (id + 5)) {
      if (s[i] != '-') flag = false;
    } else {
      if (s[i] > '9' || s[i] < '0') flag = false;
    }
    a[i] = s[i] - '0';
    cur = cur + s[i];
  }
  char b = 0;
  cur = cur + b;
  if (flag == false) return false;
  d1 = a[id] * 10 + a[id + 1];
  m1 = a[id + 3] * 10 + a[id + 4];
  y1 = a[id + 6] * 1000 + a[id + 7] * 100 + a[id + 8] * 10 + a[id + 9];
  flag = false;
  if (2012 < y1 && y1 < 2016) {
    if (0 < m1 && m1 < 13) {
      if (0 < d1 && d1 <= mon[m1]) {
        flag = true;
      }
    }
  }
  return flag;
}
int main() {
  int k, mxnow, cnt, i;
  scanf("%s", s);
  k = strlen(s);
  mm.clear();
  mxnow = -1;
  cnt = 1;
  for (i = 0; i < k - 10; i++) {
    if (chk(i) == false) continue;
    if (mm.find(cur) == mm.end()) {
      mm[cur] = cnt;
      rec[cnt] = 0;
      kip[cnt] = cur;
      cnt++;
    }
    int now;
    now = mm[cur];
    rec[now]++;
    mxnow = max(rec[now], mxnow);
  }
  for (i = 1; i < cnt; i++) {
    if (rec[i] == mxnow) {
      printf("%s\n", kip[i].c_str());
      break;
    }
  }
  return 0;
}
