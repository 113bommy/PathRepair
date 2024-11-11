#include <bits/stdc++.h>
using namespace std;
string ask(const vector<pair<int, int>> &v) {
  if (v.empty()) return "";
  int size = (int)v.size();
  printf("Q %d", size);
  for (auto &each : v) {
    printf(" %d %d", each.first, each.second);
  }
  puts("");
  fflush(stdout);
  static char ret[100005];
  scanf("%s", ret);
  if (ret[0] == '-') exit(0);
  return string(ret);
}
string straight_ask(const vector<int> &v) {
  if (v.size() <= 1) return "";
  vector<pair<int, int>> pairs;
  for (int i = 0; (i + 1) < (int)v.size(); i += 2) {
    pairs.emplace_back(v[i], v[i + 1]);
  }
  string a = ask(pairs);
  pairs.clear();
  for (int i = 1; (i + 1) < (int)v.size(); i += 2) {
    pairs.emplace_back(v[i], v[i + 1]);
  }
  string b = ask(pairs);
  string c = "";
  for (int i = int(0); i < int(a.size()); i++) {
    c += a[i];
    if (i < (int)b.size()) {
      c += b[i];
    }
  }
  return c;
}
inline int other(int a, int b) { return 3 - (a + b); }
const int MAX = 1e5 + 5;
int color[MAX];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> v;
    for (int i = int(1); i < int(n + 1); i++) v.push_back(i);
    string a = straight_ask(v);
    vector<vector<int>> groups;
    vector<int> cur{1};
    for (int i = int(1); i < int(n); i++) {
      if (a[i - 1] == '0') {
        groups.push_back(cur);
        cur.clear();
      }
      cur.push_back(i + 1);
    }
    groups.push_back(cur);
    if ((int)groups.size() == 1) {
      printf("A %d 0 0\n", (int)groups[0].size());
      for (auto &each : groups[0]) {
        printf("%d ", each);
      }
      puts("");
      puts("");
      puts("");
      fflush(stdout);
      continue;
    }
    for (auto &each : groups[0]) color[each] = 0;
    for (auto &each : groups[1]) color[each] = 1;
    vector<int> rep;
    for (auto &each : groups) {
      rep.push_back(each[0]);
    }
    vector<int> fodase[2];
    for (int i = int(0); i < int(rep.size()); i++) {
      fodase[i & 1].push_back(rep[i]);
    }
    string b = straight_ask(fodase[0]);
    string c = straight_ask(fodase[1]);
    int g = 2;
    for (int i = int(0); i < int(b.size() + c.size()); i++) {
      string &cur_s = i % 2 == 0 ? b : c;
      if (cur_s[i / 2] == '0') {
        int col = other(color[groups[g - 2][0]], color[groups[g - 1][0]]);
        for (auto &each : groups[g]) color[each] = col;
      } else {
        for (auto &each : groups[g]) color[each] = color[groups[g - 2][0]];
      }
      g++;
    }
    int cnt[3] = {0};
    for (int i = int(1); i < int(n + 1); i++) cnt[color[i]]++;
    printf("A %d %d %d\n", cnt[0], cnt[1], cnt[2]);
    for (int i = int(0); i < int(3); i++) {
      vector<int> ak;
      for (int j = int(1); j < int(n + 1); j++) {
        if (color[j] == i) ak.push_back(j);
      }
      for (int j = int(0); j < int(ak.size()); j++) {
        if (j) printf(" ");
        printf("%d", ak[j]);
      }
      puts("");
    }
    fflush(stdout);
  }
  return 0;
}
