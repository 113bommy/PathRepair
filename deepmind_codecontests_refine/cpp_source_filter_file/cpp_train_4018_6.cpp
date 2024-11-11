#include <bits/stdc++.h>
using namespace std;
bool c[1001], visited[2001];
vector<int> a;
queue<int> q;
void bfs() {
  int s = q.front();
  q.pop();
  int it = q.front();
  q.pop();
  if (s == 0) {
    cout << it;
    return;
  }
  for (int i = 0; i < a.size(); i++)
    if (-1000 <= s + a[i] && s + a[i] <= 1000 && !visited[s + a[i] + 1000]) {
      q.push(s + a[i]);
      q.push(it + 1);
      visited[s + a[i] + 1000] = 1;
    }
  if (it == 1000) {
    cout << -1;
    return;
  }
  if (!q.empty())
    bfs();
  else
    cout << -1;
}
int main() {
  int n, b;
  cin >> b >> n;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (c[x] == 0) {
      c[x] = 1;
      a.push_back(x - b);
      q.push(x - b);
      q.push(1);
      visited[x - b + 1000] = 1;
    }
  }
  bfs();
}
