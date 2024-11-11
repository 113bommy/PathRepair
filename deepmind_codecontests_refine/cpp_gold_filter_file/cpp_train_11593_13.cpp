#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
struct Team {
  int point, win, fail, time;
  string name;
  bool operator<(const Team& t) const {
    if (point != t.point) return point > t.point;
    if (win - fail != t.win - t.fail) return win - fail > t.win - t.fail;
    if (win != t.win) return win > t.win;
    return name < t.name;
  }
} p[5], temp[5];
map<string, int> id;
int tol, x, y;
string name[2];
int getid(string s) {
  int& ret = id[s];
  if (ret) return ret;
  p[++tol].name = s;
  return ret = tol;
}
bool ok(int a, int b) {
  for (int i = 1; i <= 4; ++i) temp[i] = p[i];
  temp[x].point += 3;
  temp[x].win += a;
  temp[x].fail += b;
  temp[y].win += b;
  temp[y].fail += a;
  sort(temp + 1, temp + 5);
  return temp[1].name == "BERLAND" || temp[2].name == "BERLAND";
}
int main() {
  int a, b;
  for (int i = 0; i < 5; ++i) {
    cin >> name[0] >> name[1];
    scanf("%d:%d", &a, &b);
    int u = getid(name[0]), v = getid(name[1]);
    p[u].win += a;
    p[u].fail += b;
    p[u].time += 1;
    p[v].win += b;
    p[v].fail += a;
    p[v].time += 1;
    if (a == b)
      p[u].point += 1, p[v].point += 1;
    else if (a > b)
      p[u].point += 3;
    else
      p[v].point += 3;
  }
  x = 0, y = 0;
  for (int i = 1; i <= 4; ++i) {
    if (p[i].time == 2) {
      if (p[i].name == "BERLAND")
        x = i;
      else
        y = i;
    }
  }
  int l = -1, r = 10000;
  for (int i = 1; i <= 500; ++i) {
    for (int j = 0; j < i; ++j) {
      if (ok(i, j)) {
        if (i - j < r - l) {
          r = i, l = j;
        } else if (i - j == r - l && j < l) {
          r = i, l = j;
        }
      }
    }
  }
  if (l != -1)
    printf("%d:%d\n", r, l);
  else
    printf("IMPOSSIBLE\n");
  return 0;
}
