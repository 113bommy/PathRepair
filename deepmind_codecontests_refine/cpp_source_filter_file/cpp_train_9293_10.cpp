#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
int main() {
  long long n, m, l, r;
  cin >> n >> m >> l >> r;
  vector<long long> x[N + 1];
  for (long long i = 1; i * i <= N; i++) {
    for (long long j = i; j <= N; j += i) {
      x[j].push_back(i);
    }
  }
  long long left = m + 1, right = m, count[m + 1], id[m + 1];
  memset(id, -1, sizeof(id));
  memset(count, 0, sizeof(count));
  vector<long long> ans[n + 1];
  set<long long> divs;
  for (long long i = 1; i <= n; i++) {
    long long x1 = i;
    long long nl = ((l + i - 1) / i), nr = (r / i);
    while (left > nl) {
      left--;
      for (long long j = 0; j < x[left].size(); j++) {
        if (count[x[left][j]] == 0) {
          divs.insert(x[left][j]);
        }
        count[x[left][j]]++;
        id[x[left][j]] = left;
      }
    }
    while (right > nr) {
      for (long long j = 0; j < x[right].size(); j++) {
        count[x[right][j]]--;
        if (count[x[right][j]] == 0) {
          divs.erase(x[right][j]);
        }
      }
      right--;
    }
    set<long long>::iterator it;
    for (long long j = 0; j < x[i].size(); j++) {
      long long a = x[i][j];
      it = divs.upper_bound(a);
      if (it == divs.end()) {
        continue;
      }
      long long b = *it;
      if ((x1 / a) * b <= n) {
        ans[x1] = {x1, id[b], (x1 / a) * b, (id[b] / b) * a};
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (ans[i].size() == 0) {
      cout << "-1"
           << "\n";
    } else {
      cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " "
           << ans[i][3] << "\n";
    }
  }
}
