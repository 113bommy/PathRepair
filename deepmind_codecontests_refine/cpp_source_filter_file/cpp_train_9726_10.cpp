#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int dp[2][2][N];
bool win[2][N];
int ch[N][26];
int words[N];
int sz;
string name[30];
string seq[N];
int cnt[N];
int cnt_of_word;
void insert(string s) {
  int p = 0;
  for (int i = 0; i < (int)s.length(); i++) {
    int id = s[i] - 'a';
    if (!ch[p][id]) {
      memset(ch[sz], 0, sizeof(ch[sz]));
      words[sz] = 0;
      ch[p][id] = sz++;
    }
    p = ch[p][id];
  }
  words[p] = ++cnt_of_word;
}
int find(string s) {
  int p = 0;
  for (int i = 0; i < (int)s.length(); i++) {
    int id = s[i] - 'a';
    if (!ch[p][id]) return 0;
    p = ch[p][id];
  }
  return words[p];
}
void gao(string now, string T) {
  int id = find(T);
  if (id == 0) return;
  int n = (now == "") ? 0 : find(now);
  bool f = not win[1][id];
  int a = dp[1][1][id] + cnt[id];
  int b = dp[1][0][id];
  if (f > win[0][n] || (f == win[0][n] && a > dp[0][0][n]) ||
      (f == win[1][id] && a == dp[0][0][n] && b < dp[0][1][n])) {
    win[0][n] = f;
    dp[0][0][n] = dp[1][1][id] + cnt[id];
    dp[0][1][n] = dp[1][0][id];
  }
  f = not win[0][id];
  a = dp[0][1][id] + cnt[id];
  b = dp[0][0][id];
  if (f > win[1][n] || (f == win[1][n] && a > dp[1][0][n]) ||
      (f == win[1][id] && a == dp[1][0][n] && b < dp[1][1][n])) {
    win[1][n] = f;
    dp[1][0][n] = dp[0][1][id] + cnt[id];
    dp[1][1][n] = dp[0][0][id];
  }
}
int cmp(string a, string b) {
  return a.size() < b.size() || (a.size() == b.size() && a < b);
}
int main() {
  int n;
  while (cin >> n) {
    int tot = 0;
    for (int i = 0; i < n; i++) {
      cin >> name[i];
      for (int j = 0; j < (int)name[i].length(); j++) {
        for (int k = 1; (j + k) <= (int)name[i].length(); k++) {
          seq[++tot] = name[i].substr(j, k);
        }
      }
    }
    sort(seq + 1, seq + tot + 1, cmp);
    tot = unique(seq + 1, seq + tot + 1) - seq - 1;
    sz = 1;
    memset(ch[0], 0, sizeof(ch[0]));
    words[0] = 0;
    cnt_of_word = 0;
    seq[0] = "";
    for (int i = 1; i <= tot; i++) insert(seq[i]);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= tot; i++) {
      for (int j = 0; j < n; j++) {
        if (name[j].find(seq[i]) != string::npos) {
          cnt[i]++;
        }
      }
      int mx = 0, sum = 0;
      for (int j = 0; j < (int)seq[i].length(); j++) {
        mx = max(mx, seq[i][j] - 'a' + 1);
        sum += seq[i][j] - 'a' + 1;
      }
      cnt[i] += sum * mx;
    }
    memset(win, false, sizeof(win));
    memset(dp, 0, sizeof(dp));
    for (int i = tot; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        string tmp(1, 'a' + j);
        gao(seq[i], seq[i] + tmp);
        gao(seq[i], tmp + seq[i]);
      }
    }
    if (win[0][0]) {
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
    cout << dp[0][0][0] << " " << dp[0][1][0] << endl;
  }
  return 0;
}
