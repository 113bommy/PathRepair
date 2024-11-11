#include <bits/stdc++.h>
using namespace std;
vector<long long> vi[100100];
long long a[100100], b[10000], pos[10000];
long long u, v, n, k, m, r, x, y, cnt = 1, cnt1, z, zz, o, oo, cnt2;
long long i, j, ans;
map<long long, long long> mapp;
int main() {
  cin >> n >> m >> k;
  for (i = 1; i <= n; i++) {
    cin >> x;
    b[i] = x;
    pos[x] = i;
  }
  for (i = 0; i < m; i++) {
    cin >> y;
    ans += (pos[y] - 1) / k + 1;
    if (pos[y] != 1) {
      z = b[pos[y - 1]];
      swap(b[pos[y]], b[pos[y] - 1]);
      pos[z]++;
      pos[y]--;
    }
  }
  cout << ans;
}
