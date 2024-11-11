#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  t = 1;
  while (t--) {
    long long n, i, j, w, h, count = 1, sum = 0, total, k, T, breaks = 0, m,
                             c = 0, start;
    string s;
    queue<int> q;
    cin >> n >> m;
    if (m % 2 == 0) {
      start = m / 2;
    } else
      start = m / 2 + 1;
    q.push(start);
    for (i = 1; i < n; i++) {
      if (start <= m / 2 && start + count <= m) {
        start = start + count;
        q.push(start);
      } else if (start - count >= 1) {
        start = start - count;
        q.push(start);
      } else {
        q.push(start);
      }
      count++;
      if (count >= m) {
        count = 1;
        start = (m + 1) / 2;
        if (i < n) {
          q.push(start);
          i++;
        }
      }
    }
    while (!q.empty()) {
      cout << q.front() << endl;
      q.pop();
    }
  }
}
