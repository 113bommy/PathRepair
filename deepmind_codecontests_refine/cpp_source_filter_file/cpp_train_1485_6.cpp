#include <bits/stdc++.h>
using namespace std;
struct node {
  int x;
  int y;
} a[200005];
int n, m;
int w[100005], s[100005];
bool used[100005], vis[100005];
vector<int> food[100005];
queue<int> q;
stack<int> st;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= m; i++) {
    cin >> a[i].x >> a[i].y;
    s[a[i].x]++;
    food[a[i].x].push_back(i);
    s[a[i].y]++;
    food[a[i].y].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] <= w[i]) {
      used[i] = 1;
      for (int j = 0; j < food[i].size(); j++) q.push(food[i][j]);
    }
  }
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    if (vis[i] == 0) {
      st.push(i);
      s[a[i].x]--;
      s[a[i].y]--;
    }
    vis[i] = 1;
    if (used[a[i].x] == 0 && s[a[i].x] <= w[a[i].x]) {
      used[a[i].x] = 1;
      for (int j = 0; j < food[a[i].x].size(); j++) q.push(food[a[i].x][j]);
    }
    if (used[a[i].y] == 0 && s[a[i].y] <= w[a[i].y]) {
      used[a[i].y] = 1;
      for (int j = 0; j < food[a[i].y].size(); j++) q.push(food[a[i].y][j]);
    }
  }
  if (st.size() == m) {
    cout << "ALIVE\n";
    while (!st.empty()) {
      cout << st.top() << ' ';
      st.pop();
    }
  } else {
    cout << "DEAD";
  }
  return 0;
}
