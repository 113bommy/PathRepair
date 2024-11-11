#include <bits/stdc++.h>
using namespace std;
vector<pair<vector<int>, vector<int> > > ans;
vector<int> two[100005], three[100005];
int arr[100005], st[100005], two_cnt, three_cnt;
bool vis[100005];
inline vector<int> rsh(const vector<int> &a) {
  vector<int> res;
  int n = a.size();
  for (int i = 1; i < n; i++) res.push_back(a[i]);
  res.push_back(a[0]);
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    arr[i]--;
  }
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    int x = i, cnt = 0;
    while (!vis[x]) {
      vis[x] = true;
      st[cnt++] = x;
      x = arr[x];
    }
    while (cnt >= 5) {
      vector<int> tmp;
      for (int i = cnt - 5; i < cnt; i++) tmp.push_back(st[i]);
      ans.push_back(make_pair(tmp, rsh(tmp)));
      cnt -= 5;
      if (cnt) st[cnt++] = tmp[0];
    }
    if (cnt == 2)
      two[two_cnt++] = {st[0], st[1]};
    else if (cnt == 3)
      three[three_cnt++] = {st[0], st[1], st[2]};
    else if (cnt == 4) {
      vector<int> tmp;
      for (int i = 0; i < 4; i++) tmp.push_back(st[i]);
      ans.push_back(make_pair(tmp, rsh(tmp)));
    }
  }
  while (true) {
    bool f = true;
    while (two_cnt && three_cnt) {
      f = false;
      two_cnt--;
      three_cnt--;
      vector<int> x = {two[two_cnt][0], two[two_cnt][1], three[three_cnt][0],
                       three[three_cnt][1], three[three_cnt][2]};
      vector<int> y = {two[two_cnt][1], two[two_cnt][0], three[three_cnt][1],
                       three[three_cnt][2], three[three_cnt][0]};
      ans.push_back(make_pair(x, y));
    }
    if (three_cnt >= 2) {
      f = false;
      vector<int> x = three[--three_cnt];
      vector<int> y = three[--three_cnt];
      vector<int> fir = {x[0], x[1], x[2], y[0], y[1]};
      vector<int> sec = {x[1], x[2], x[0], y[1], y[0]};
      ans.push_back(make_pair(fir, sec));
      two[two_cnt++] = {y[0], y[2]};
    }
    if (f) break;
  }
  while (two_cnt >= 2) {
    vector<int> x = two[--two_cnt];
    vector<int> y = two[--two_cnt];
    vector<int> fir = {x[0], x[1], y[0], y[1]};
    vector<int> sec = {x[1], x[0], y[1], y[0]};
    ans.push_back(make_pair(fir, sec));
  }
  if (three_cnt) {
    vector<int> x = three[--three_cnt];
    ans.push_back(make_pair(x, rsh(x)));
  }
  if (two_cnt) {
    vector<int> x = two[--two_cnt];
    ans.push_back(make_pair(x, rsh(x)));
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); i++) {
    int x = ans[i].first.size();
    printf("%d\n", x);
    for (int j = 0; j < x; j++)
      printf("%d%c", ans[i].first[j] + 1, " \n"[j + 1 == x]);
    for (int j = 0; j < x; j++)
      printf("%d%c", ans[i].second[j] + 1, " \n"[j + 1 == x]);
  }
  return 0;
}
