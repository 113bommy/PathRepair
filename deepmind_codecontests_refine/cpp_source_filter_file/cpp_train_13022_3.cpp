#include <bits/stdc++.h>
using namespace std;
int L[100], R[100];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, count = 0;
  bool lie = false;
  queue<int> q;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> L[i] >> R[i];
  }
  for (int i = 1; i < m; i++) {
    lie = false;
    for (int j = 0; j < n; j++) {
      if (i >= L[j] and R[j] >= i) {
        lie = true;
        break;
      }
    }
    if (!lie) {
      count++;
      q.push(i);
    }
  }
  if (count == 0) {
    cout << 0;
    return 0;
  }
  cout << count << endl;
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  return 0;
}
