#include <bits/stdc++.h>
using namespace std;
vector<int> a;
struct net {
 public:
  int c, f;
  net(int c, int f) : c(c), f(f) {}
  net() : c(0), f(0) {}
};
net q[205][205];
vector<bool> primes(20000, false);
int net_s, net_t;
int even_num = 0, odd_num = 0;
int n;
void make_primes() {
  for (int i = 2; i < 20000; i++) {
    if (primes[i] == false) {
      int cur = 2 * i;
      while (cur < 20000) {
        primes[cur] = true;
        cur += i;
      }
    }
  }
}
bool prime(int x) {
  if (!primes[x]) {
    return true;
  }
  return false;
}
void make_net() {
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 != 0) {
      odd_num++;
      q[net_s][i + 1] = net(2, 0);
      q[i + 1][net_s] = net(0, 0);
    }
    if (a[i] % 2 == 0) {
      q[net_t][i + 1] = net(0, 0);
      q[i + 1][net_t] = net(2, 0);
      even_num++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (prime(a[i] + a[j]) && a[i] % 2 != 0) {
        q[j + 1][i + 1] = net(0, 0);
        q[i + 1][j + 1] = net(1, 0);
      }
    }
  }
}
void sate_edge(int u, int v, int flow) {
  q[u][v].f += flow;
  q[v][u].f -= flow;
}
int bfs(int u) {
  vector<int> f(205, -1);
  bool fl = false;
  queue<pair<int, int> > p;
  p.push(make_pair(u, 1000000007));
  int flow = -1;
  int preRevival = -1;
  int curRevival = -1;
  f[u] = u;
  while (!p.empty()) {
    pair<int, int> cur = p.front();
    p.pop();
    if (cur.second <= 0) {
      continue;
    }
    for (int i = 0; i < 201; i++) {
      if (f[i] == -1 && q[cur.first][i].c - q[cur.first][i].f > 0) {
        p.push(make_pair(
            i, min(cur.second, q[cur.first][i].c - q[cur.first][i].f)));
        f[i] = cur.first;
        if (i == net_t) {
          flow = min(cur.second, q[cur.first][i].c - q[cur.first][i].f);
          curRevival = net_t;
          preRevival = cur.first;
          fl = true;
          break;
        }
      }
    }
    if (fl) {
      break;
    }
  }
  if (flow <= 0) {
    return 0;
  }
  while (curRevival != preRevival) {
    sate_edge(preRevival, curRevival, flow);
    curRevival = preRevival;
    preRevival = f[preRevival];
  }
  return flow;
}
int getMaxFlow() {
  int ans = 0;
  while (true) {
    int flow = bfs(0);
    if (flow == 0) {
      return ans;
    }
    ans += flow;
  }
  return ans;
}
vector<vector<int> > m(205, vector<int>(0));
vector<vector<int> > ans;
vector<bool> f(205, false);
void dfs(int u, int p) {
  f[u] = true;
  for (int i = 0; i < m[u].size(); i++) {
    if (f[m[u][i]] == false) {
      dfs(m[u][i], p);
    }
  }
  ans[p].push_back(u);
}
void makeAnswer() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (q[i][j].f > 0) {
        m[i].push_back(j);
        m[j].push_back(i);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (f[i] == false) {
      ans.push_back(vector<int>(0));
      dfs(i, ans.size() - 1);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].size() << " ";
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
int main() {
  srand(time(NULL));
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  net_s = 0;
  net_t = n + 1;
  make_primes();
  make_net();
  int flow = getMaxFlow();
  if (flow != even_num * 2) {
    cout << "Impossible" << endl;
    return 0;
  }
  makeAnswer();
}
