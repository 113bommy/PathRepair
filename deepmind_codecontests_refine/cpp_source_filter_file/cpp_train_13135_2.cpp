#include <bits/stdc++.h>
using namespace std;
int d[2 * 1000001], v1[2 * 1000001], v2[2 * 1000001], a[1000001], i, n, tt, tt2,
    kq;
void BFS1(int s, int k) {
  queue<int> q;
  if (v2[s] == 0) {
    q.push(s);
    v1[s] = k;
  }
  while (q.size() > 0) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 21; i++)
      if ((u >> i) & 1) {
        int v = u - (1 << i);
        if (v1[v] == 0) {
          q.push(v);
          v1[v] = k;
        }
      }
  }
}
void BFS2(int s, int k) {
  queue<int> q;
  if (v2[s] > 0) return;
  if (d[s] == 0 || d[s] > k) {
    q.push(s);
    if (d[s] == 0)
      d[s] = k;
    else
      v2[s] = k;
  }
  while (q.size() > 0) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 21; i++)
      if ((u >> i) & 1) {
        int v = u - (1 << i);
        if (v2[v] > 0) continue;
        if (d[v] == 0 || d[v] > k) {
          q.push(v);
          if (d[v] == 0)
            d[v] = k;
          else
            v2[v] = k;
        }
      }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) BFS1(a[i], i);
  for (i = n; i >= 1; i--) BFS2(a[i], i);
  for (tt = 0; tt <= 2000000; tt++) {
    tt2 = 0;
    if (v2[tt] == 0) continue;
    for (i = 20; i >= 0; i--) {
      if ((tt >> i) & 1) continue;
      if (v1[tt2 | (1 << i)] < v2[tt] && v1[tt2 | (1 << i)] > 0)
        tt2 |= (1 << i);
    }
    kq = max(kq, tt | tt2);
  }
  cout << kq;
}
