#include <bits/stdc++.h>
using namespace std;
void smain();
int main() {
  ios_base::sync_with_stdio(false);
  smain();
  return 0;
}
const long long N = 300;
long long a[N];
long long gr[N][N];
long long flw[N][N];
long long pred[N], fl[N], que[N];
long long n;
bool prime(long long a) {
  for (long long j = 2; j * j <= a; j++) {
    if (a % j == 0) return false;
  }
  return true;
}
vector<vector<long long> > ans;
void dfs(long long pos, long long q) {
  if (fl[pos] != 0) return;
  fl[pos] = 1;
  ans[q].push_back(pos);
  if (a[pos] % 2 == 0) {
    for (long long i = 0; i < n; i++) {
      if (gr[pos][i] > 0 && flw[pos][i] == 0 && fl[i] == 0) {
        dfs(i, q);
      }
    }
  } else {
    for (long long i = 0; i < n; i++) {
      if (gr[pos][i] > 0 && flw[i][pos] == 0 && fl[i] == 0) {
        dfs(i, q);
      }
    }
  }
}
void smain() {
  cin >> n;
  long long src = n;
  long long dst = n + 1;
  long long nn = n + 2;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      gr[src][i] = 2;
      flw[src][i] = 2;
      for (long long j = 0; j < n; j++) {
        if (a[j] % 2 == 1 && prime(a[i] + a[j])) {
          gr[i][j] = 1;
          gr[j][i] = 1;
          flw[i][j] = 1;
        }
      }
    } else {
      gr[i][dst] = 2;
      flw[i][dst] = 2;
    }
  }
  long long ll, rr, fr;
  while (true) {
    for (long long i = 0; i < nn; i++) {
      fl[i] = 0;
      pred[i] = -1;
    }
    ll = 0;
    rr = 0;
    que[0] = src;
    fl[src] = 1;
    while (ll <= rr) {
      fr = que[ll];
      for (long long i = 0; i < nn; i++) {
        if (flw[fr][i] > 0 && fl[i] == 0) {
          fl[i] = 1;
          rr++;
          que[rr] = i;
          pred[i] = fr;
        }
      }
      ll++;
    }
    if (fl[dst] == 0) break;
    ll = dst;
    rr = 10000;
    while (ll != src) {
      fr = pred[ll];
      rr = min(rr, flw[fr][ll]);
      ll = fr;
    }
    ll = dst;
    while (ll != src) {
      fr = pred[ll];
      flw[fr][ll] -= rr;
      flw[ll][fr] += rr;
      ll = fr;
    }
  }
  for (long long i = 0; i < nn; i++) {
    if (flw[src][i] != 0 || flw[i][dst] != 0) {
      cout << "Impossible";
      return;
    }
  }
  for (long long i = 0; i < n; i++) {
    fl[i] = 0;
  }
  long long q = 0;
  for (long long i = 0; i < n; i++) {
    if (fl[i] == 0 && a[i] % 2 == 0) {
      ans.push_back(vector<long long>());
      dfs(i, q);
      q++;
    }
  }
  cout << ans.size() << endl;
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i].size();
    for (long long j = 0; j < ans[i].size(); j++) {
      cout << ' ' << (a[ans[i][j]]);
    }
    cout << '\n';
  }
}
