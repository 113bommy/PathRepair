#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
}
long long A[500006];
long long B[500006];
long long C[500006];
vector<long long> V;
vector<long long> Ans;
vector<pair<long long, long long> > VP;
map<long long, long long> M;
vector<long long> prime;
bool mark[10000008];
long long N = 1e7;
void seive() {
  int limit = sqrt(N * 1.0) + 2;
  mark[1] = 1;
  for (int i = 4; i <= N; i += 2) mark[i] = 1;
  prime.push_back(2);
  for (int i = 3; i <= N; i += 2) {
    if (!mark[i]) {
      prime.push_back(i);
      if (i <= limit) {
        for (int j = i * i; j <= N; j += i * 2) mark[j] = 1;
      }
    }
  }
}
int m;
long long MAx;
vector<long long> G[100006];
long long f(long long mid) {
  long long sum = 0;
  for (int i = 1; i <= m; i++) {
    if (mid != 0 and mid <= G[i].size()) {
      if (G[i][mid - 1] > 0) {
        sum += G[i][mid - 1];
      }
    }
  }
  return sum;
}
void ternary_search(long long l, long long r) {
  long long eps = 0;
  while (r >= l) {
    long long m1 = l + (r - l) / 3;
    long long m2 = r - (r - l) / 3;
    long long f1 = f(m1);
    long long f2 = f(m2);
    MAx = max(MAx, f1);
    MAx = max(MAx, f2);
    if (f1 < f2)
      l = m1 + 1;
    else
      r = m2 - 1;
  }
  MAx = max(MAx, f(l));
  MAx = max(MAx, f(r));
}
int main() {
  fastIO();
  long long a, b, c, d, n, k, l, p, q, r, t, x, y;
  long long cnt = 0, cntr = 0, sum = 0, ans = 1, check = 0;
  long long Max = 0, Max1 = -1e18 + 1, Min = 1LL << 62;
  string s, s1, s3, s4;
  t = 1;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a >> b;
      G[a].push_back(b);
    }
    r = 0;
    for (int i = 1; i <= m; i++) {
      sort(G[i].rbegin(), G[i].rend());
      r = max((int)G[i].size(), (int)r);
    }
    for (int i = 1; i <= m; i++) {
      if (G[i].size() > 0 and G[i][0] > 0) {
        sum += G[i][0];
      }
      for (int j = 1; j < G[i].size(); j++) {
        G[i][j] += G[i][j - 1];
      }
    }
    ternary_search(0, r);
    cout << max(sum, MAx) << endl;
  }
  return 0;
}
