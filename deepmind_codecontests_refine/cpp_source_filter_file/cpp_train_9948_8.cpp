#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
const int INF = 1e9 + 10;
const long long LINF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 100;
const int MN = 5e4 + 10;
const int MT = 1e6 + 10;
int n, m, T;
vector<int> adj[MN];
int mk[MN];
int L[20 + 5][MN], len[MN];
int Now[MT];
void input() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b), adj[b].push_back(a);
  }
  T = 0;
  for (int i = 0; i < n; ++i) {
    cin >> len[i];
    for (int j = 0; j < len[i]; ++j) {
      cin >> L[j][i], --L[j][i];
      T = max(T, L[j][i]);
    }
  }
  ++T;
}
void prep() {
  for (int i = 0; i < n; ++i) {
    int c1 = 0, c2 = 0;
    for (int j = 0; j < ((int)(adj[i]).size()); ++j) {
      int v = adj[i][j];
      if (mk[v] == 1)
        ++c1;
      else if (mk[v] == 2)
        ++c2;
    }
    if (c1 > c2)
      mk[i] = 2;
    else
      mk[i] = 1;
  }
}
void Output() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < len[i]; ++j) {
      if (Now[L[j][i]] == mk[i]) {
        cout << L[j][i] + 1 << ' ';
        break;
      }
    }
  }
  cout << '\n';
  for (int i = 0; i < T; ++i) cout << Now[i] << ' ';
  cout << '\n';
}
void solve() {
  int num = 100;
  while (num--) {
    srand(time(NULL));
    for (int i = 0; i < T; ++i) Now[i] = rand() % 2 + 1;
    bool t = false;
    for (int i = 0; i < n; ++i) {
      bool flag = false;
      for (int j = 0; j < len[i]; ++j) {
        if (Now[L[j][i]] == mk[i]) {
          flag = true;
          break;
        }
      }
      if (!flag) {
        t = true;
        break;
      }
    }
    if (!t) {
      Output();
      return;
    }
  }
  cout << "HI" << '\n';
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  input();
  prep();
  solve();
  return 0;
}
