#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <class T>
ostream& prnt(ostream& out, T v) {
  out << v.size() << '\n';
  for (auto e : v) out << e << ' ';
  return out;
}
template <class T>
ostream& operator<<(ostream& out, vector<T> v) {
  return prnt(out, v);
}
template <class T>
ostream& operator<<(ostream& out, set<T> v) {
  return prnt(out, v);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, map<T1, T2> v) {
  return prnt(out, v);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  return out << '(' << p.first << ' ' << p.second << ')';
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
const long long N = 1505;
long long n, use[N], a[N], cnt[155], ant[N], ans = 100000;
vector<long long> v[N];
long long bfs(long long node, long long dpt) {
  long long dmin = 1000000;
  memset(use, 0, sizeof use);
  memset(ant, 0, sizeof ant);
  queue<long long> q;
  q.push(node);
  use[node] = 1;
  ant[node] = -1;
  while (!q.empty()) {
    long long x = q.front();
    q.pop();
    for (auto i : v[x])
      if (!use[i]) {
        use[i] = use[x] + 1;
        ant[i] = x;
        q.push(i);
      } else if (i != ant[x]) {
        dmin = min(dmin, use[x] + use[i] - 1);
      }
  }
  return dmin;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    for (long long j = 0; j <= 60; j++) {
      if ((1LL << j) & a[i]) cnt[j]++;
      if (cnt[j] >= 3) {
        return cout << "3\n", 0;
      }
    }
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  while (n && !a[n]) n--;
  for (long long i = 1; i <= n; i++)
    for (long long j = i + 1; j <= n; j++)
      if (a[i] & a[j]) {
        v[i].push_back(j);
        v[j].push_back(i);
      }
  for (long long i = 1; i <= n; i++) {
    ans = min(ans, bfs(i, 1));
  }
  if (ans > n) ans = -1;
  cout << ans << '\n';
}
