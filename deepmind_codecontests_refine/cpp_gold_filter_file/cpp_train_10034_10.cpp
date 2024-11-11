#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> res;
int len;
bool good[10];
int a[100];
bool was[10];
string s[4];
bool good_s(string s) {
  if (s == "0") return true;
  if (s[0] == '0') return false;
  int x;
  sscanf(s.c_str(), "%d", &x);
  return x >= 0 && x <= 255;
}
void split(int group, int start) {
  s[group] = "";
  if (group == 3) {
    for (int i = start; i < len; i++) s[3] += '0' + a[i];
    if (good_s(s[3])) {
      string ss = "";
      for (int j = 0; j <= 3; j++) {
        if (j) ss += ".";
        ss += s[j];
      }
      res.push_back(ss);
    }
    return;
  }
  for (int l = 0; l < 3; l++) {
    if (start + l >= len) break;
    s[group] += '0' + a[start + l];
    if (good_s(s[group])) {
      split(group + 1, start + l + 1);
    }
  }
}
void test() {
  int cnt = 0;
  memset(was, 0, sizeof was);
  for (int i = 0; i < len; i++)
    if (!was[a[i]]) was[a[i]] = true, cnt++;
  if (cnt != n) return;
  split(0, 0);
}
void go(int index) {
  int index_r = len - index - 1;
  if (index > index_r) {
    test();
    return;
  }
  for (int d = 0; d <= 9; d++)
    if (good[d]) {
      a[index] = a[index_r] = d;
      go(index + 1);
    }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    good[x] = true;
  }
  for (len = 4; len <= 12; len++) go(0);
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
  return 0;
}
