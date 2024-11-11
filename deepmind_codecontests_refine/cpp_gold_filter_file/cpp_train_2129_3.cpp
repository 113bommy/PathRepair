#include <bits/stdc++.h>
using namespace std;
pair<int, int> card[105];
pair<int, int> known[105];
bool Check(int N, int pos) { return (bool)(N & (1 << pos)); }
int n;
bool pos(int state) {
  memset((known), 0, sizeof(known));
  ;
  for (int i = 0; i < 5; ++i) {
    if (Check(state, i) == 0) continue;
    for (int j = 0; j < n; ++j) {
      if (card[j].first == i + 1) {
        known[j].first = i + 1;
      }
    }
  }
  for (int i = 0; i < 5; ++i) {
    if (Check(state, i + 5) == 0) continue;
    for (int j = 0; j < n; ++j) {
      if (card[j].second == i + 1) {
        known[j].second = i + 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (known[i] == known[j]) {
        return false;
      }
    }
  }
  return true;
}
map<char, int> mp;
int ccc(int v) {
  if (!v) return 0;
  return (v & 1) + ccc(v >> 1);
}
int main() {
  mp['R'] = 1;
  mp['G'] = 2;
  mp['B'] = 3;
  mp['Y'] = 4;
  mp['W'] = 5;
  int cnt = 0;
  scanf("%d", &cnt);
  char tmp[10];
  n = 0;
  pair<int, int> sss;
  set<pair<int, int> > xx;
  for (int i = 0; i < cnt; ++i) {
    scanf("%s", tmp);
    sss.first = mp[tmp[0]];
    sss.second = tmp[1] - '0';
    if (xx.find(sss) == xx.end()) {
      xx.insert(sss);
      card[n++] = sss;
    }
  }
  int ans = 20;
  for (int i = 0; i < (1 << 10); ++i) {
    if (pos(i)) {
      ans = min(ans, ccc(i));
    }
  }
  cout << ans << endl;
  return 0;
}
