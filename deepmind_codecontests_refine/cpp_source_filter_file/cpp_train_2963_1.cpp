#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e5 + 10;
string ar[max_n];
string y[max_n];
map<string, int> M;
vector<int> adj[max_n * 2];
queue<int> Q;
pair<int, int> best[max_n * 2];
string tlc(string s) {
  for (int i = 0; i < s.size(); i++)
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}
int cntR(string s) {
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) cnt += (s[i] == 'r');
  return cnt;
}
bool cmp(string a, string b) {
  int ra = cntR(a), rb = cntR(b);
  return ra < rb || ra == rb && a.size() < b.size();
}
int main() {
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> ar[i];
    ar[i] = tlc(ar[i]);
  }
  int n;
  cin >> n;
  string x;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> x >> y[i];
    x = tlc(x);
    y[i] = tlc(y[i]);
    if (!M.count(x)) M[x] = cnt++;
    if (!M.count(y[i])) M[y[i]] = cnt++;
    adj[M[y[i]]].push_back(M[x]);
  }
  sort(y, y + n, cmp);
  memset(best, -1, sizeof best);
  for (int i = 0; i < n; i++) {
    int at = M[y[i]];
    if (best[at].first == -1) {
      best[at].first = cntR(y[i]);
      best[at].second = y[i].size();
      Q.push(at);
      for (; Q.size(); Q.pop()) {
        int from = Q.front();
        for (int j = 0; j < adj[from].size(); j++) {
          int to = adj[from][j];
          if (best[to].first == -1) {
            best[to].first = best[at].first;
            best[to].second = best[at].second;
            Q.push(to);
          }
        }
      }
    }
  }
  int a = 0, b = 0;
  for (int i = 0; i < m; i++) {
    pair<int, int> p;
    p.first = cntR(ar[i]);
    p.second = ar[i].size();
    if (M.count(ar[i])) p = min(best[M[ar[i]]], p);
    a += p.first;
    b += p.second;
  }
  cout << a << " " << b << endl;
  return 0;
}
