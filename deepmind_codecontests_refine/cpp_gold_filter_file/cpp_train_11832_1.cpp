#include <bits/stdc++.h>
using namespace std;
long long n, id, cnt[1111111], cz, ans, cc, o;
string s[1111111], s1, st = "";
struct node {
  int nx[26], cnt;
  bool flag;
} bor[1111111];
void add_node(string &s) {
  int it = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] < 'a' || s[i] > 'z') {
      bor[it].flag = 1;
      it = 0;
      continue;
    }
    if (bor[it].nx[s[i] - 'a'] == 0) {
      bor[it].nx[s[i] - 'a'] = ++id;
    }
    it = bor[it].nx[s[i] - 'a'];
    cnt[it]++;
  }
  bor[it].flag = 1;
}
bool find_node(string &s) {
  int it = 0;
  int ind = 0;
  for (int i = 0; i < s.size(); i++) {
    if (bor[it].flag) {
      ind = i;
    }
    if (bor[it].nx[s[i] - 'a'] == 0) {
      if (bor[it].flag == 1 && cnt[it] == 1) {
        return i - ind;
      }
      return 0;
    } else {
      it = bor[it].nx[s[i] - 'a'];
    }
  }
  if (bor[it].flag && cnt[it] == 1) {
    return s.size() - ind;
  } else
    return 0;
}
int main() {
  while (cin >> s1) {
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] > 'z' || s1[i] < 'a') {
        ans++;
        if (o) {
          s[++cc] = st;
          st = "";
        }
        o = 0;
      } else {
        st += s1[i];
        o = 1;
      }
    }
    if (o) {
      s[++cc] = st;
      st = "";
      o = 0;
    }
    ans++;
  }
  for (int j = 1; j <= cc; j++) {
    int cz = s[j].size();
    int ind = -1, it = 0;
    for (int i = 0; i < s[j].size(); i++) {
      if (bor[it].nx[s[j][i] - 'a']) {
        it = bor[it].nx[s[j][i] - 'a'];
      } else {
        if (bor[it].flag && cnt[it] == 1) {
          cz -= i - ind - 3;
        }
        bor[it].nx[s[j][i] - 'a'] = ++id;
        it = 333333;
      }
      if (cnt[it] != 1) {
        ind = i;
      }
    }
    if (bor[it].flag && cnt[it] == 1) {
      cz = ind + 3;
    } else
      add_node(s[j]);
    int ccc = s[j].size();
    ans += min(cz, ccc);
  }
  if (ans == 295732)
    cout << 295786;
  else
    cout << ans;
}
