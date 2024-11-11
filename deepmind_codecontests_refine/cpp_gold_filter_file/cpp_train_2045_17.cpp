#include <bits/stdc++.h>
using namespace std;
int f() {
  puts("f");
  return 1;
}
int g() {
  puts("g");
  return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> seq;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    seq.push_back(x - 1);
  }
  vector<vector<int> > req;
  for (int i = 0; i < n; i++) {
    if (seq[i] == i || seq[i] < 0) continue;
    vector<int> rec;
    for (int j = i; seq[j] >= 0;) {
      rec.push_back(j);
      int t = seq[j];
      seq[j] = -1;
      j = t;
    }
    req.push_back(rec);
  }
  vector<pair<vector<int>, vector<int> > > ans;
  for (int i = 0; i < (int)req.size(); i++) {
    vector<int> &cur = req[i];
    while (cur.size() > 5) {
      vector<int> s(5), t(5);
      for (int j = 0; j < 5; j++) {
        s[4 - j] = cur.back();
        cur.pop_back();
      }
      cur.push_back(s[0]);
      for (int j = 1; j < 5; j++) t[j - 1] = s[j];
      t[4] = s[0];
      ans.push_back(make_pair(s, t));
    }
  }
  vector<vector<int> > req2, req3;
  for (int i = 0; i < (int)req.size(); i++) {
    vector<int> &cur = req[i];
    if (cur.size() == 2) {
      req2.push_back(cur);
      continue;
    } else if (cur.size() == 3) {
      req3.push_back(cur);
      continue;
    }
    int l = cur.size();
    vector<int> t(l);
    for (int j = 1; j < l; j++) t[j - 1] = cur[j];
    t[l - 1] = cur[0];
    ans.push_back(make_pair(cur, t));
  }
  for (int i = 0; i < (int)req3.size(); i++) {
    vector<int> &cur = req3[i];
    vector<int> s = cur, t(3);
    for (int j = 1; j < 3; j++) t[j - 1] = cur[j];
    t[2] = cur[0];
    if (!req2.empty()) {
      vector<int> &x = req2.back();
      s.push_back(x[0]);
      s.push_back(x[1]);
      t.push_back(x[1]);
      t.push_back(x[0]);
      req2.pop_back();
    } else if (i + 1 < (int)req3.size()) {
      i++;
      vector<int> &y = req3[i];
      s.push_back(y[0]);
      s.push_back(y[1]);
      t.push_back(y[1]);
      t.push_back(y[0]);
      vector<int> tmp;
      tmp.push_back(y[0]);
      tmp.push_back(y[2]);
      req2.push_back(tmp);
    }
    ans.push_back(make_pair(s, t));
  }
  for (int i = 0; i < (int)req2.size(); i += 2) {
    vector<int> &cur = req2[i];
    vector<int> s = cur, t(2);
    t[0] = cur[1];
    t[1] = cur[0];
    if (i + 1 < (int)req2.size()) {
      s.push_back(req2[i + 1][0]);
      s.push_back(req2[i + 1][1]);
      t.push_back(req2[i + 1][1]);
      t.push_back(req2[i + 1][0]);
    }
    ans.push_back(make_pair(s, t));
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < (int)ans.size(); i++) {
    vector<int> &src = ans[i].first;
    vector<int> &dst = ans[i].second;
    int l = src.size();
    printf("%d\n", l);
    for (int j = 0; j < l; j++) printf("%d ", src[j] + 1);
    putchar('\n');
    for (int j = 0; j < l; j++) printf("%d ", dst[j] + 1);
    putchar('\n');
  }
  return 0;
}
