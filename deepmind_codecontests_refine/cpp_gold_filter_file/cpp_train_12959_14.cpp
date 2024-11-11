#include <bits/stdc++.h>
using namespace std;
const int maxN = 10000;
struct cl {
  int r;
  int c;
};
long long run() {
  int n;
  cin >> n;
  long long d[n];
  for (int i = 0; i < n; ++i) cin >> d[i];
  int N = 2 * n - 2;
  int p[N];
  for (int i = 0; i < N; ++i) p[i] = i < n ? i : N - i;
  int u[n], v[n];
  memset(u, 0, sizeof(u));
  memset(v, 0, sizeof(v));
  int D = 0;
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    ++u[a - 1];
  }
  long long S = 0;
  for (int i = 0; i < m; ++i) {
    ++v[p[i % N]];
    if (i < m - 1) S += abs(d[p[(i + 1) % N]] - d[p[i % N]]);
  }
  for (int i = 0; i < n; ++i) D += abs(u[i] - v[i]);
  long long ans = -1;
  if (D == 0) ans = S;
  for (int st = 1; st < N; st++) {
    int oldSt = st - 1;
    int oldNd = st + m - 2;
    int nd = st + m - 1;
    oldNd %= N;
    nd %= N;
    S += abs(d[p[nd]] - d[p[oldNd]]);
    S -= abs(d[p[st]] - d[p[oldSt]]);
    set<int> affect({p[oldSt], p[nd]});
    int oldSum = 0;
    for (auto elem : affect) oldSum += abs(u[elem] - v[elem]);
    v[p[oldSt]]--;
    v[p[nd]]++;
    for (auto elem : affect) D += abs(u[elem] - v[elem]);
    D -= oldSum;
    if (D == 0) {
      if (ans != -1 && S != ans) return -1;
      ans = S;
    }
  }
  return ans;
}
int main() {
  long long ret = run();
  cout << ret << endl;
  return 0;
}
