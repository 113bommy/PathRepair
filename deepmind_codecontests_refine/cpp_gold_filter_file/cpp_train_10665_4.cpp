#include <bits/stdc++.h>
using namespace std;
int trie[100005][26];
int status[100005];
long long n, k;
int dfs(int idx) {
  bool flag = true;
  int sta[26];
  int total = 0;
  int cwin = 0;
  int cfai = 0;
  int cpre = 0;
  int caft = 0;
  memset(sta, -1, sizeof(sta));
  for (int i = 0; i < 26; ++i) {
    if (trie[idx][i] != -1) {
      flag = false;
      sta[i] = dfs(trie[idx][i]);
      total++;
      if (sta[i] == 1)
        cwin++;
      else if (sta[i] == 0)
        cfai++;
      else if (sta[i] == 2)
        cpre++;
      else if (sta[i] == 3)
        caft++;
    }
  }
  if (flag) {
    status[idx] = 1;
  } else {
    if (cwin == total)
      status[idx] = 0;
    else if (cfai == total)
      status[idx] = 1;
    else if ((cwin && cfai) || caft)
      status[idx] = 2;
    else if (cwin && cfai == 0 && caft == 0)
      status[idx] = 0;
    else if (cfai && cwin == 0 && caft == 0)
      status[idx] = 1;
    else if (cpre == total)
      status[idx] = 3;
  }
  return status[idx];
}
int main() {
  while (cin >> n >> k) {
    memset(trie, -1, sizeof(trie));
    memset(status, -1, sizeof(status));
    int cur = 1;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      int p = 0;
      for (int j = 0; j < s.size(); ++j) {
        int idx = s[j] - 'a';
        if (trie[p][idx] == -1) {
          trie[p][idx] = cur;
          p = cur;
          cur++;
        } else {
          p = trie[p][idx];
        }
      }
    }
    dfs(0);
    bool flag = true;
    if (status[0] == 1) {
      flag = false;
    } else if (status[0] == 0) {
      if (k % 2 == 0) flag = false;
    } else if (status[0] == 3) {
      flag = false;
    }
    if (flag)
      cout << "First" << endl;
    else
      cout << "Second" << endl;
  }
  return 0;
}
