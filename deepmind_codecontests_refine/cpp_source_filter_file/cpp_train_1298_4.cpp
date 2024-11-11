#include <bits/stdc++.h>
using namespace std;
const int MN = 100100;
int n, m, k;
long long p, h[MN], a[MN];
long long h2[MN];
bool check(long long x) {
  fill_n(h2, n, x);
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      q;
  for (int i = 0; i < n; i++) {
    if (h2[i] - m * a[i] >= 0) continue;
    q.push(pair<int, int>(h2[i] / a[i] - 1, i));
  }
  int count = 0;
  for (; count < m * k; count++) {
    if (q.empty()) break;
    pair<int, int> hit = q.top();
    q.pop();
    if (hit.first < count / k) return false;
    int i = hit.second;
    h2[i] += p;
    if (h2[i] - m * a[i] >= 0) continue;
    q.push(pair<int, int>(h2[i] / a[i] - 1, i));
  }
  for (int i = 0; i < n; i++) {
    if (h2[i] - m * a[i] >= h[i]) continue;
    count += (h[i] - (h2[i] - m * a[i]) + p - 1) / p;
    if (count >= m * k) return false;
  }
  return true;
}
int main() {
  cin >> n >> m >> k >> p;
  for (int i = 0; i < n; i++) {
    cin >> h[i] >> a[i];
  }
  long long l = 0, r = 1LL << 55;
  while (r - l > 1) {
    long long md = (l + r) / 2;
    if (check(md)) {
      r = md;
    } else {
      l = md;
    }
  }
  cout << r << endl;
  return 0;
}
