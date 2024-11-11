#include <bits/stdc++.h>
using namespace std;
int md;
int num[301], st[601][601], in[601], out[601], cnt[601][601];
vector<int> A, B;
bool z[601];
int n;
int F(int v) {
  if (z[v]) return num[v];
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    if (st[i][v]) ans = (ans + (long long)st[i][v] * F(i)) % md;
  z[v] = true;
  num[v] = ans;
  return num[v];
}
int main() {
  int m;
  cin >> n >> m >> md;
  memset(st, 0, sizeof(st));
  memset(in, 0, sizeof(in));
  memset(out, 0, sizeof(out));
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    ++in[y];
    ++out[x];
    ++st[x][y];
  }
  A.clear();
  B.clear();
  for (int i = 1; i <= n; ++i) {
    if (!in[i]) A.push_back(i);
    if (!out[i]) B.push_back(i);
  }
  for (int it = 0; it <= (int)(A).size() - 1; ++it) {
    int v = A[it];
    memset(z, false, sizeof(z));
    z[v] = true;
    num[v] = 1;
    for (int j = 0; j <= (int)(B).size() - 1; ++j) cnt[it][j] = F(B[j]);
  }
  int nn = (int)(A).size();
  for (int i = 0; i <= nn - 1; ++i)
    for (int j = 0; j <= nn - 1; ++j) {
      if (A[i] == B[j] && !in[A[i]] && !out[B[j]])
        cnt[i][j] = 1;
      else if (A[i] == B[j])
        cnt[i][j] = 0;
    }
  long long ans = 1;
  for (int i = 0; i <= nn - 1; ++i) {
    for (int j = i + 1; j <= nn - 1; ++j)
      while (cnt[j][i] != 0) {
        int d = cnt[i][i] / cnt[j][i];
        for (int k = 0; k <= nn - 1; ++k)
          cnt[i][k] = (cnt[i][k] - (long long)cnt[j][k] * d) % md,
          swap(cnt[i][k], cnt[j][k]);
        ans = -ans;
      }
    ans = ans * cnt[i][i] % md;
  }
  cout << (ans + md) % md << endl;
  return 0;
}
