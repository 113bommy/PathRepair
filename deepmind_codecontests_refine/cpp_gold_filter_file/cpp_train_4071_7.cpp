#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long INF = 1000000000;
template <class T>
inline void read(T &x) {
  char c;
  int flag = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag *= -1;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= flag;
  return;
}
vector<long long> v[3000 + 5];
int main() {
  long long glbmn = LLONG_MAX;
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    v[x].push_back(y);
  }
  for (int j = 1; j <= m; ++j) sort(v[j].begin(), v[j].end());
  for (int i = 1; i <= n; ++i) {
    long long buy = 0, cnt = 0;
    priority_queue<long long> pq;
    for (int j = 2; j <= m; ++j) {
      buy += max((long long)v[j].size() - i + 1, 0LL);
    }
    for (int j = 2; j <= m; ++j) {
      int nb = max((long long)v[j].size() - i + 1, 0LL);
      for (int k = 0; k < nb; ++k) cnt += v[j][k];
      for (int k = nb; k < v[j].size(); ++k) pq.push(-v[j][k]);
    }
    long long f0 = i - buy - v[1].size();
    while (f0 && !pq.empty()) {
      long long f = -pq.top();
      pq.pop();
      cnt += f;
      f0--;
    }
    if (f0) continue;
    glbmn = min(glbmn, cnt);
  }
  cout << glbmn << endl;
}
