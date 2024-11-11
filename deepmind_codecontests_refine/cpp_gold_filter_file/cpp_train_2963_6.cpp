#include <bits/stdc++.h>
using namespace std;
const pair<int, int> inf = pair<int, int>(1e9, 1e9);
vector<int> G[3 * 100005];
map<string, int> name;
int tot, n, m, x[100005];
pair<int, int> cnt[3 * 100005];
int getid(string &s) {
  int len = (int)s.length();
  int c = 0;
  for (int i = 0; i < len; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a' - 'A';
    if (s[i] == 'r') c++;
  }
  if (name.find(s) != name.end()) {
    return name[s];
  } else {
    cnt[tot] = pair<int, int>(c, len);
    return name[s] = tot++;
  }
}
string a, b;
queue<int> que;
bool inq[3 * 100005];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    x[i] = getid(a);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    int ca = getid(a);
    int cb = getid(b);
    G[cb].push_back(ca);
  }
  for (int i = 0; i < tot; i++) {
    que.push(i);
    inq[i] = true;
  }
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    inq[v] = false;
    for (vector<int>::iterator it = G[v].begin(); it != G[v].end(); it++) {
      int to = *it;
      if (cnt[to] > cnt[v]) {
        cnt[to] = cnt[v];
        if (!inq[to]) {
          que.push(to);
          inq[to] = false;
        }
      }
    }
  }
  long long r = 0, tl = 0;
  for (int i = 0; i < n; i++) {
    r += cnt[x[i]].first;
    tl += cnt[x[i]].second;
  }
  cout << r << " " << tl << endl;
  return 0;
}
