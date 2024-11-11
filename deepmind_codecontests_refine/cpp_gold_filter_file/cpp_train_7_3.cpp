#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1123456;
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
void vout(T s) {
  cout << s << endl;
  exit(0);
}
long long bp(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
set<long long> s[MAXN];
long long n, m, k;
long long kol[MAXN];
long long ans;
bool fl[MAXN];
pair<long long, long long> a[MAXN];
queue<long long> q;
void add(long long x) {
  if (fl[x]) return;
  ans--;
  fl[x] = 1;
  q.push(x);
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  ans = n;
  vector<long long> res(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].first >> a[i].second;
    kol[a[i].first]++;
    kol[a[i].second]++;
    s[a[i].first].insert(a[i].second);
    s[a[i].second].insert(a[i].first);
  }
  for (int i = 1; i <= n; i++)
    if (!fl[i] && kol[i] < k) {
      add(i);
      while (!q.empty()) {
        long long x = q.front();
        q.pop();
        for (auto i : s[x]) {
          kol[i]--;
          if (kol[i] < k) add(i);
        }
      }
    }
  for (int i = m - 1; i >= 0; i--) {
    res[i] = ans;
    if (!fl[a[i].first] && !fl[a[i].second]) {
      kol[a[i].first]--;
      kol[a[i].second]--;
      s[a[i].first].erase(a[i].second);
      s[a[i].second].erase(a[i].first);
      if (kol[a[i].first] < k) add(a[i].first);
      if (kol[a[i].second] < k) add(a[i].second);
      while (!q.empty()) {
        long long x = q.front();
        q.pop();
        for (auto i : s[x]) {
          kol[i]--;
          if (kol[i] < k) add(i);
        }
      }
    }
  }
  for (auto i : res) cout << i << "\n";
  return 0;
}
