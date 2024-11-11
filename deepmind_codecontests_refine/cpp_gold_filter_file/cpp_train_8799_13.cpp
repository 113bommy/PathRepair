#include <bits/stdc++.h>
using namespace std;
int customer[1000][1000];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  deque<int> dq;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    dq.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> customer[i][j];
  }
  int t = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int cnt = 0;
      for (deque<int>::iterator l = dq.begin(); l != dq.end(); l++) {
        cnt++;
        if (*l == customer[i][j]) {
          int x = *l;
          dq.erase(l);
          dq.push_front(x);
          t += cnt;
          break;
        }
      }
    }
  }
  cout << t;
  return 0;
}
