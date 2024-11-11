#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
int next239[100000], t[100000];
vector<int> prev239[100000];
int color[100000], was[100000], col[100000];
vector<pair<int, int> > res;
pair<int, int> ans1[100000], ans2[100000];
int next2[100000];
queue<int> q;
void parse(int x) {
  was[x] = 1;
  col[next239[x]]--;
  if (col[next239[x]] == 0) q.push(next239[x]);
}
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
pair<int, int> table[2][100001];
int o[2][100001];
pair<int, int> get(int x, int y) { return make_pair(1, t[x] != t[y]); }
void calc(int x) {
  pair<int, int> sum0 = make_pair(0, 0);
  pair<int, int> sum1 = make_pair(0, 0);
  for (int i = 0; i < (((int)(prev239[x]).size())); i++) {
    int u = prev239[x][i];
    if (was[u] == 0) continue;
    calc(u);
    sum0 = sum0 + ans1[u];
    sum1 = sum1 + ans1[u];
  }
  pair<int, int> a2 = sum1;
  next2[x] = -1;
  for (int i = 0; i < (((int)(prev239[x]).size())); i++) {
    int u = prev239[x][i];
    if (was[u] == 0) continue;
    pair<int, int> tmp = sum1 + ans2[u] - ans1[u] + get(x, u);
    if (tmp > a2) {
      a2 = tmp;
      next2[x] = u;
    }
  }
  ans1[x] = a2;
  ans2[x] = sum0;
}
void add(int x, int f) {
  for (int i = 0; i < (((int)(prev239[x]).size())); i++) {
    int u = prev239[x][i];
    if (was[u] == 0) continue;
    if (u == next2[x] && f == 1) {
      add(u, 0);
      res.push_back(make_pair(x, u));
    } else
      add(u, 1);
  }
}
pair<int, int> getans(int x) {
  vector<int> mas;
  int cur = x;
  do {
    mas.push_back(cur);
    color[cur] = 1;
    cur = next239[cur];
  } while (next239[cur] != x);
  mas.push_back(cur);
  color[cur] = 1;
  int n = ((int)(mas).size());
  for (int i = 0; i < (n); i++) calc(mas[i]);
  mas.push_back(mas[0]);
  for (int l = 0; l < (2); l++) {
    table[l][n] = make_pair(0, 0);
  }
  for (int l = 0; l < (2); l++)
    for (int i = (n)-1; i >= 0; i--) {
      pair<int, int> &ans = table[l][i];
      if (i == n - 1) {
        if (l == 0) {
          ans = get(mas[i], mas[0]) + ans2[mas[i]];
          o[l][i] = 1;
        } else {
          ans = ans1[mas[i]];
          o[l][i] = 0;
        }
      } else {
        if (i == 0 && l == 0) {
          ans = table[l][i + 1] + ans2[mas[0]];
          o[l][i] = 0;
          continue;
        }
        ans = ans1[mas[i]] + table[l][i + 1];
        o[l][i] = 0;
        if (l != 0 || i != n - 2) {
          pair<int, int> tmp = get(mas[i], mas[i + 1]) + ans2[mas[i]] +
                               ans2[mas[i + 1]] + table[l][i + 2];
          if (ans < tmp) {
            ans = tmp;
            o[l][i] = 1;
          }
        }
      }
    }
  int cl = 0;
  if (table[1][0] > table[0][0]) cl = 1;
  int cp = 0;
  while (cp < n) {
    if (o[cl][cp]) {
      res.push_back(make_pair(mas[cp], mas[cp + 1]));
      add(mas[cp], 0);
      if (cp + 1 < n) add(mas[cp + 1], 0);
      cp += 2;
    } else {
      if (cl == 0 && cp == 0)
        add(mas[cp], 0);
      else
        add(mas[cp], 1);
      cp++;
    }
  }
  return max(table[1][0], table[0][0]);
}
int main() {
  cin >> n;
  for (int i = 0; i < (n); i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    col[a]++;
    prev239[a].push_back(i);
    next239[i] = a;
    t[i] = b;
  }
  for (int i = 0; i < (n); i++)
    if (col[i] == 0) q.push(i);
  while (!q.empty()) {
    parse(q.front());
    q.pop();
  }
  pair<int, int> ans = make_pair(0, 0);
  memset(color, -1, sizeof(color));
  for (int i = 0; i < (n); i++)
    if (!was[i] && color[i] == -1) {
      ans = ans + getans(i);
    }
  cout << ans.first << ' ' << ans.second << endl;
  for (int i = 0; i < (((int)(res).size())); i++) {
    cout << res[i].first + 1 << ' ' << res[i].second + 1 << endl;
  }
  return 0;
}
