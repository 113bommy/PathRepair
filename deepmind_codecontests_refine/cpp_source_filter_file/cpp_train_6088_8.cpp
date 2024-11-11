#include <bits/stdc++.h>
using namespace std;
map<int, string> result;
map<string, int> result1;
char to_lowercase(char c) {
  if (c >= 'A' && c <= 'Z') return c + 32;
  return c;
}
vector<int> v[210];
int level[210];
bool vis[210];
void bfs(int s) {
  memset(vis, false, sizeof vis);
  queue<int> q;
  q.push(s);
  level[s] = max(0, level[s]);
  vis[s] = true;
  while (!q.empty()) {
    int p = q.front();
    q.pop();
    for (int i = 0; i < v[p].size(); i++) {
      if (vis[v[p][i]] == false) {
        level[v[p][i]] = level[p] + 1;
        q.push(v[p][i]);
        vis[v[p][i]] = true;
      }
    }
  }
}
int n;
string s1, s2, s3;
int t = -1;
int t1, t2;
int main() {
  std::locale loc;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2 >> s3;
    for (char &c : s1) {
      c = to_lowercase(c);
    }
    for (char &c : s3) {
      c = to_lowercase(c);
    }
    if (result1.find(s1) == result1.end()) {
      t++;
      result[t] = s1;
      result1[s1] = t;
    }
    if (result1.find(s3) == result1.end()) {
      t++;
      result[t] = s3;
      result1[s3] = t;
    }
    v[result1[s3]].push_back(result1[s1]);
  }
  int maxi = 0;
  for (int o = 0; o < 200; o++) {
    bfs(o);
  }
  for (int q = 0; q < 200; q++) {
    maxi = max(maxi, level[q] + 1);
  }
  cout << maxi << endl;
  return 0;
}
