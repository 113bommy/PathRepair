#include <bits/stdc++.h>
using namespace std;
long long i, j, p, n, m, k, a[11], bases[12];
vector<long long> v[11];
map<long long, bool> b, f;
struct Pic {
  long long raz;
  long long a[11];
  long long h;
} t, t2;
priority_queue<Pic> q;
bool operator<(Pic a, Pic b) { return (a.raz > b.raz); }
long long calc_hash(long long b[]) {
  long long ans = 0;
  long long p = 1;
  for (int ii = 1; ii <= n; ii++) {
    ans += (b[ii] * bases[ii]) % 1000000007;
    ans %= 1000000007;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  bases[0] = 1;
  for (i = 1; i <= 10; i++) {
    bases[i] = bases[i - 1] * 200000;
    bases[i] %= 1000000007;
  }
  for (i = 1; i <= n; i++) {
    cin >> m;
    for (j = 1; j <= m; j++) {
      cin >> p;
      v[i].push_back(p);
    }
  }
  cin >> m;
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      cin >> a[j];
    }
    f[calc_hash(a)] = 1;
  }
  for (i = 1; i <= n; i++) t.a[i] = v[i].size();
  t.h = calc_hash(t.a);
  q.push(t);
  while (!q.empty()) {
    t = q.top();
    q.pop();
    if (!b[t.h]) {
      if (f[t.h] == 0) {
        for (i = 1; i <= n; i++) cout << t.a[i] << " ";
        cout << endl;
        return 0;
      }
      b[t.h] = 1;
      for (i = 1; i <= n; i++) {
        if (t.a[i] > 1) {
          t2 = t;
          p = t.h - (bases[i] * t.a[i]) % 1000000007;
          p += (bases[i] * (t.a[i] - 1)) % 1000000007;
          p %= 1000000007;
          while (p < 0) p += 1000000007;
          t2.h = p;
          if (b[t2.h]) continue;
          t2.a[i]--;
          t2.raz = v[i][t.a[i] - 1] - v[i][t.a[i] - 2] + t.raz;
          q.push(t2);
        }
      }
    }
  }
  return 0;
}
