#include <bits/stdc++.h>
using namespace std;
int n, i, a[101], sum(0), cnt(1), j, l, Max;
bool flag[101];
void Solve() {
  cout << n - 1 << endl;
  fill(flag + 1, flag + n + 1, true);
  deque<int> q;
  q.push_front(1);
  while (cnt < n) {
    int u = q.front();
    q.pop_front();
    for (i = 1; i <= a[u]; i++) {
      Max = 0;
      l = 0;
      for (j = 2; j <= n; j++) {
        if (flag[j] == true && a[j] >= Max) {
          l = j;
          Max = a[j];
        }
      }
      cout << u << " " << l << endl;
      flag[l] = false;
      cnt++;
      if (cnt == n) return;
      q.push_back(l);
    }
  }
}
void Init() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum < n - 1 || a[1] == 0)
    cout << -1;
  else
    Solve();
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  Init();
}
