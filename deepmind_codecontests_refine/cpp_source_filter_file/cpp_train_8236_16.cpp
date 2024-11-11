#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
struct edge {
  long long d, c;
} t[300010];
multiset<int> s1;
stack<pair<long long, long long> > s2;
long long ans;
int n;
long long a;
int i, j, k;
long long calc(int i) { return (t[i + 1].d - t[i].d) * (t[i + 1].d - t[i].d); }
int main() {
  n = read();
  a = read();
  for (i = 1; i <= n; i++) {
    t[i].d = read();
    t[i].c = read();
    t[i].c = t[i - 1].c + a - t[i].c;
    ans = max(ans, t[i].c - t[i - 1].c);
  }
  for (i = 1; i <= n; i++) {
    if (s1.size()) ans = max(ans, t[i].c - *s1.begin());
    if (i == n) break;
    long long gap = calc(i);
    long long minc = t[i - 1].c;
    while (s2.size() && calc(s2.top().first) <= gap) {
      minc = min(minc, s2.top().second);
      s1.erase(s1.find(s2.top().second + calc(s2.top().first)));
      s2.pop();
    }
    s2.push(make_pair(i, minc));
    s1.insert(minc + gap);
  }
  cout << ans << endl;
}
