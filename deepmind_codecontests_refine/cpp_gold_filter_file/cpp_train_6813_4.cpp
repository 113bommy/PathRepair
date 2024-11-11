#include <bits/stdc++.h>
using namespace std;
long a[1004][1005];
long long int cp[1000006], rp[1000004];
int main() {
  long long int n, m, k, p;
  cin >> n >> m >> k >> p;
  priority_queue<pair<long long int, long long int> > c, r;
  long long int s = 0;
  for (long i = 1; i <= n; i++) {
    s = 0;
    for (long j = 1; j <= m; j++) {
      cin >> a[i][j];
      s = s + a[i][j];
    }
    r.push(make_pair(s, i));
  }
  for (long j = 1; j <= m; j++) {
    s = 0;
    for (long i = 1; i <= n; i++) {
      s = s + a[i][j];
    }
    c.push(make_pair(s, j));
  }
  for (long i = 1; i <= k; i++) {
    long long int h = c.top().first;
    int t = c.top().second;
    cp[i] = cp[i - 1] + h;
    c.pop();
    h = h - n * p;
    c.push(make_pair(h, t));
  }
  for (long i = 1; i <= k; i++) {
    long long int h = r.top().first;
    int t = r.top().second;
    rp[i] = rp[i - 1] + h;
    r.pop();
    h = h - m * p;
    r.push(make_pair(h, t));
  }
  long long int ma = rp[k];
  for (long long int i = 0; i <= k; i++) {
    long long int h = rp[i] + cp[k - i] - (long long)(k - i) * i * p;
    if (h > ma) ma = h;
  }
  cout << ma << endl;
}
