#include <bits/stdc++.h>
using namespace std;
void seive() {
  long long int spf[1000000];
  spf[1] = 1;
  for (int i = 2; i < 1000000; i++) spf[i] = i;
  for (int i = 4; i < 1000000; i += 2) spf[i] = 2;
  for (int i = 3; i * i < 1000000; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < 1000000; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
long long int printDivisors(long long int n) {
  for (long long int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        return i;
      else
        return n / i;
    }
  }
  return 1;
}
vector<long long int> getFactorization(long long int x) {
  vector<long long int> ret;
  while (x != 1) {
  }
  return ret;
}
double nthRoot(int A, int N) {
  double xPre = rand() % 10;
  double eps = 1e-3;
  double delX = INT_MAX;
  double xK;
  while (delX > eps) {
    xK = ((N - 1.0) * xPre + (double)A / pow(xPre, N - 1)) / (double)N;
    delX = abs(xK - xPre);
    xPre = xK;
  }
  return xK;
}
void segsieve(long long int l, long long int h) {
  static vector<bool> ip(100000001, true);
  for (long long int pp : ip) {
    if (pp > sqrt(h)) break;
    long long int sm = floor(l / pp) * pp;
    if (sm < l) sm += pp;
    if (sm <= pp) sm += pp;
    for (long long int m = sm; m <= h; m += pp) {
      ip[m - l] = false;
    }
  }
  long long int j = 0;
  for (long long int i = 0; i < ip.size(); i++)
    if (ip[i] && i + l != 1) {
      j++;
      if (j - 1 % 100 == 0) cout << (i + l) << "\n";
    }
}
vector<long long int> v1[1001];
vector<pair<long long int, long long int> > v3[1001];
pair<long long int, long long int> cnt[1001];
set<pair<long long int, long long int> > s1;
vector<long long int> vis(1001), par(1001);
void bfs(long long int i) {
  queue<long long int> q;
  q.push(i);
  vis[i] = 1;
  while (!q.empty()) {
    long long int c = q.front();
    q.pop();
    for (auto x : v1[c]) {
      if (!vis[x]) {
        par[x] = c;
        vis[x] = 1;
        q.push(x);
      } else if (x != par[c] && s1.find({c, x}) == s1.end()) {
        s1.insert({x, c});
        v3[i].push_back({x, c});
        cnt[i].first++;
        cnt[i].second = i;
      }
    }
  }
}
bool mycmp(long long int a, long long int b) { return cnt[a] >= cnt[b]; }
int main() {
  long long int t = 1, pp = 0;
  while (t--) {
    long long int n, j = 0, b = 0, sum1 = 0, sum2 = 0, mina = INT_MAX, maxa = 0,
                     e = 0, h = 0, g = 0, x2 = -1, y1, y2 = -1, a, l = 0, r,
                     l1 = 0, r1 = 0, x1 = 0;
    long long int sum = 0, i = 0, y = 0, c = 0;
    long long int d = 0;
    long long int k = 0, k1 = 0, k2 = 0, k3 = 0, k4 = 0;
    long long int m;
    cin >> n;
    vector<long long int> v1(n + 1);
    vector<pair<long long int, long long int> > v2(n + 1);
    for (i = 0; i < n; i++) {
      cin >> v1[i];
      v2[i].second = n - 1;
    }
    stack<long long int> s;
    v2[0].first = 0;
    s.push(0);
    for (i = 1; i < n; i++) {
      if (v1[s.top()] < v1[i]) {
        v2[i].first = s.top() + 1;
        s.push(i);
      } else {
        while (s.empty() == 0 && s.top() >= v1[i]) {
          c = s.top();
          v2[c].second = i - 1;
          s.pop();
        }
        if (s.empty())
          v2[i].first = 0;
        else
          v2[i].first = s.top() + 1;
        s.push(i);
      }
    }
    vector<long long int> v3(n + 1);
    for (i = n - 1; i >= 0; i--) {
      v3[v2[i].second - v2[i].first + 1] =
          max(v1[i], v3[v2[i].second - v2[i].first + 1]);
    }
    for (i = n - 1; i >= 1; i--) {
      v3[i] = max(v3[i + 1], v3[i]);
    }
    for (i = 1; i <= n; i++) cout << v3[i] << " ";
  }
  return 0;
}
