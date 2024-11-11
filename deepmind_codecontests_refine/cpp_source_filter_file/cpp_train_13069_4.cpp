#include <bits/stdc++.h>
using namespace std;
int a[200000];
int d[200000];
bool v[200000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int y;
    scanf("%d", &y);
    a[i] = y - 1;
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  v[0] = true;
  while (!q.empty()) {
    pair<int, int> c = q.front();
    q.pop();
    int i = c.first;
    int dist = c.second;
    if (i + 1 < n && !v[i + 1]) {
      v[i + 1] = true;
      q.push({i + 1, dist + 1});
    }
    if (i - i >= 0 && !v[i - 1]) {
      v[i - 1] = true;
      q.push({i - 1, dist + 1});
    }
    if (!v[a[i]]) {
      v[a[i]] = true;
      q.push({a[i], dist + 1});
    }
    d[i] = dist;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", d[i]);
  }
  cout << endl;
  return 0;
}
