#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > q;
int a[200050], n, bu[200050], m[200050];
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) cin >> a[i], bu[a[i]]++;
  cout << a[1] << endl;
  for (int i = 1; i <= n; i++)
    if (!bu[i]) q.push(make_pair(-i, i));
  for (int i = n - 1; i >= 1; i--) {
    int v = q.top().second;
    int u = q.top().first;
    q.pop();
    cout << v << " " << a[i] << endl;
    bu[a[i]]--;
    m[a[i]] = max(m[a[i]], u);
    m[a[i]] = max(m[a[i]], a[i]);
    if (!bu[a[i]]) q.push(make_pair(-m[a[i]], a[i]));
  }
  cin >> n;
}
