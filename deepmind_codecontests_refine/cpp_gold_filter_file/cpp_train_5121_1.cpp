#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> sz[200001];
vector<int> mod[200001];
long long s[200001];
int os[200001];
int db[200001];
bool v[200001];
int k;
long long sum = 0;
void unio(int a, int b) {
  s[a] += s[b];
  os[b] = a;
  s[b] = 0;
}
int holvan(int a) { return os[a]; }
bool dfs(int a) {
  if (a == k) {
    sum += s[a];
    s[a] = 0;
    return true;
  }
  v[a] = true;
  bool c = false;
  for (int i = 0; i < mod[a].size(); i++) {
    int x = mod[a][i];
    if (!v[x]) {
      c = dfs(x);
      if (c) {
        sum += s[a];
        s[a] = 0;
        return true;
      }
    }
  }
  return false;
}
long long ker(int a) {
  long long ans = s[a];
  v[a] = true;
  long long maxi = 0;
  for (int i = 0; i < mod[a].size(); i++) {
    int x = mod[a][i];
    if (!v[x]) {
      maxi = max(maxi, ker(x));
    }
  }
  return ans + maxi;
}
long long modker(int a) {
  long long ans = s[a];
  v[a] = true;
  long long maxi = 0;
  for (int i = 0; i < sz[a].size(); i++) {
    int x = sz[a][i];
    if (!v[x]) {
      maxi = max(maxi, modker(x));
    }
  }
  return ans + maxi;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    os[i] = i;
    cin >> s[i];
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    sz[x].push_back(y);
    sz[y].push_back(x);
  }
  if (m == n - 1) {
    cin >> k;
    cout << modker(k) << endl;
    return 0;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    db[i] = sz[i].size();
    if (db[i] == 1) {
      q.push(i);
    }
  }
  while (q.size() > 0) {
    int a = q.front();
    q.pop();
    v[a] = true;
    for (int i = 0; i < sz[a].size(); i++) {
      int x = sz[a][i];
      db[x]--;
      if (db[x] == 1) {
        q.push(x);
      }
    }
  }
  cin >> k;
  for (int i = 1; i <= n; i++) {
    if (!v[i]) {
      os[i] = 0;
      s[0] += s[i];
      s[i] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!v[i]) {
      os[i] = 0;
      s[0] += s[i];
      for (int j = 0; j < sz[i].size(); j++) {
        int x = sz[i][j];
        if (v[x]) {
          mod[0].push_back(x);
        }
      }
    } else {
      for (int j = 0; j < sz[i].size(); j++) {
        int x = holvan(sz[i][j]);
        mod[i].push_back(x);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    v[i] = false;
  }
  if (os[k] != 0) {
    dfs(0);
  }
  for (int i = 0; i <= n; i++) {
    v[i] = false;
  }
  cout << sum + ker(0);
  return 0;
}
