#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
struct node {
  int len;
  int link;
  int firstpos;
  map<char, int> nxt;
};
const int mxn = 100005;
const int MX = mxn * 2;
node t[MX];
int sz, last;
void init() {
  sz = last = 0;
  t[0].len = 0;
  t[0].firstpos = 0;
  t[0].link = -1;
  sz++;
}
long long cnt[MX];
vector<pair<int, int> > v;
set<pair<int, int> > nodes;
void add_letter(char ch) {
  int cur = sz++;
  t[cur].len = t[last].len + 1;
  t[cur].firstpos = t[cur].len;
  cnt[cur] = 1;
  nodes.insert({t[cur].len, cur});
  int p;
  for (p = last; p != -1 && !t[p].nxt.count(ch); p = t[p].link)
    t[p].nxt[ch] = cur;
  if (p == -1)
    t[cur].link = 0;
  else {
    int q = t[p].nxt[ch];
    if (t[p].len + 1 == t[q].len)
      t[cur].link = q;
    else {
      int clone = sz++;
      t[clone].len = t[p].len + 1;
      t[clone].nxt = t[q].nxt;
      t[clone].link = t[q].link;
      t[clone].firstpos = t[q].firstpos;
      cnt[clone] = 0;
      nodes.insert({t[clone].len, clone});
      for (; p != -1 && t[p].nxt[ch] == q; p = t[p].link) t[p].nxt[ch] = clone;
      t[q].link = t[cur].link = clone;
    }
  }
  last = cur;
}
long long dcnt[MX];
long long dist_sub(int u) {
  long long ans = cnt[u];
  if (dcnt[u]) return dcnt[u];
  for (auto x : t[u].nxt) {
    char ch = x.first;
    ans += 1LL * dist_sub(t[u].nxt[ch]);
  }
  return dcnt[u] = ans;
}
void kth_Path(int k, int cur) {
  k -= cnt[cur];
  if (k <= 0) {
    return;
  }
  for (auto x : t[cur].nxt) {
    char ch = x.first;
    if (k > dcnt[t[cur].nxt[ch]]) {
      k -= dcnt[t[cur].nxt[ch]];
      continue;
    } else {
      cout << ch;
      kth_Path(k, t[cur].nxt[ch]);
      break;
    }
  }
}
int lcs(string s) {
  int cur = 0, ans = 0, len = 0, pos = 0;
  for (int i = 0; i < s.size(); i++) {
    while (cur && !t[cur].nxt.count(s[i])) {
      cur = t[cur].link;
      len = t[cur].len;
    }
    if (t[cur].nxt.count(s[i])) {
      cur = t[cur].nxt[s[i]];
      len++;
    }
    if (len > ans) ans = len, pos = i;
  }
  string sub = s.substr(pos - ans + 1, ans);
  return ans;
}
int main() {
  memset(cnt, 0, sizeof(cnt));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int i, j, n, m, k, q;
  string s;
  cin >> s;
  n = s.size();
  long long nn = n;
  nn *= (nn + 1);
  nn /= 2;
  cin >> k;
  if (k > n) {
    cout << "No such line.\n";
    return 0;
  }
  init();
  for (i = 0; i < n; i++) {
    add_letter(s[i]);
  }
  for (auto it = nodes.rbegin(); it != nodes.rend(); ++it) {
    cnt[t[(*it).second].link] += cnt[(*it).second];
  }
  cnt[0] = 0;
  dist_sub(0);
  kth_Path(k, 0);
  cout << endl;
}
