#include <bits/stdc++.h>
using namespace std;
long long int a[100010], b[100010], c[100010];
int main() {
  long long int k1, k2, k3, t1, t2, t3;
  cin >> k1 >> k2 >> k3 >> t1 >> t2 >> t3;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) c[i] = a[i];
  queue<pair<long long int, long long int> > q;
  for (long long int i = 1; i <= n && i <= k1; i++) {
    q.push(pair<long long int, long long int>(i, a[i]));
    b[i] = a[i] + t1;
  }
  for (long long int i = k1 + 1; i <= n; i++) {
    long long int x = q.front().second;
    x += t1;
    long long int w = a[i];
    w = max(w, x);
    q.pop();
    q.push(pair<long long int, long long int>(i, w));
    b[i] = w + t1;
  }
  for (long long int i = 1; i <= n; i++) a[i] = b[i];
  queue<pair<long long int, long long int> > newq;
  q = newq;
  for (long long int i = 1; i <= n && i <= k2; i++) {
    q.push(pair<long long int, long long int>(i, a[i]));
    b[i] = a[i] + t2;
  }
  for (long long int i = k2 + 1; i <= n; i++) {
    long long int x = q.front().second;
    x += t2;
    long long int w = a[i];
    w = max(w, x);
    q.pop();
    q.push(pair<long long int, long long int>(i, w));
    b[i] = w + t2;
  }
  for (long long int i = 1; i <= n; i++) a[i] = b[i];
  q = newq;
  for (long long int i = 1; i <= n && i <= k3; i++) {
    q.push(pair<long long int, long long int>(i, a[i]));
    b[i] = a[i] + t3;
  }
  for (long long int i = k3 + 1; i <= n; i++) {
    long long int x = q.front().second;
    x += t3;
    long long int w = a[i];
    w = max(w, x);
    q.pop();
    q.push(pair<long long int, long long int>(i, w));
    b[i] = w + t3;
  }
  long long int res = 0;
  for (long long int i = 1; i <= n; i++) res = max(res, b[i] - c[i]);
  cout << res << endl;
}
