#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3c3c3c3c;
const long long LINF = 1ll * INF * INF * 2;
const int N = 1000001;
int n, m;
const long long MAX = 1e18;
string s;
int num = 0;
vector<int> S;
vector<vector<int>> v;
bool type[N];
int cur;
long long lim[N];
bool ans[N];
void dfs(int cur) {
  for (int nxt : v[cur])
    if (nxt > 0) dfs(nxt);
  if (type[cur]) {
    lim[cur] = 0;
    for (int nxt : v[cur]) {
      if (nxt > 0)
        lim[cur] += lim[nxt];
      else
        lim[cur] += 1;
    }
  } else {
    lim[cur] = MAX;
    for (int nxt : v[cur]) {
      if (nxt < 0) {
        lim[cur] = 1;
        break;
      }
      lim[cur] = min(lim[cur], lim[nxt]);
    }
  }
}
void make(int cur) {
  if (type[cur]) {
    for (int nxt : v[cur]) {
      if (nxt < 0)
        ans[-nxt] = true;
      else
        make(nxt);
    }
  } else {
    for (int nxt : v[cur]) {
      if (nxt < 0) {
        ans[-nxt] = true;
        return;
      }
    }
    for (int nxt : v[cur]) {
      if (lim[nxt] == lim[cur]) {
        make(nxt);
        return;
      }
    }
  }
}
void proc() {
  scanf("%d", &n);
  getline(cin, s);
  S.clear();
  v.clear();
  num = 0;
  cur = 0;
  v.push_back(vector<int>());
  S.push_back(0);
  for (int i = 0; i < ((int)((s).size())); i++) {
    char c = s[i];
    if (c == '(') {
      num++;
      v.push_back(vector<int>());
      v[S.back()].push_back(num);
      S.push_back(num);
    }
    if (c == ')') {
      S.pop_back();
    }
    if (c == '*') {
      v[S.back()].push_back(--cur);
    }
    if (c == 'P') {
      type[S.back()] = true;
    }
    if (c == 'S') {
      type[S.back()] = false;
    }
  }
  dfs(0);
  long long val = 1ll * n * lim[0];
  for (int i = 1; i <= -cur; i++) ans[i] = 0;
  make(0);
  printf("REVOLTING");
  for (int i = 1; i <= -cur; i++) printf(" %d", ans[i] ? val : 0);
  printf("\n");
}
int main(void) {
  int TC;
  scanf("%d", &TC);
  while (TC--) proc();
}
