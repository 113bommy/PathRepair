#include <bits/stdc++.h>
using namespace std;
const int maxn = int(1e5) + 5;
int A[maxn];
int R[maxn];
int C[maxn];
set<pair<int, int> >::iterator get_top(set<pair<int, int> >& pq) {
  auto it = pq.end();
  --it;
  return it;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    R[A[i]] = i;
  }
  fill(C + 1, C + n + 1, 1);
  set<pair<int, int> > pq;
  for (int i = 1; i <= n; i++) {
    pq.insert({C[i], i});
  }
  for (int i = 1; i <= n; i++) {
    auto back = get_top(pq);
    if (C[R[i]] != back->first) {
      cout << "No\n";
      return;
    }
    int cnt = C[R[i]];
    pq.erase({C[R[i]], i});
    C[R[i]] = 0;
    for (int j = R[i] + 1; j <= n; j++) {
      if (C[j] > 0) {
        pq.erase({C[j], j});
        C[j] += cnt;
        pq.insert({C[j], j});
        break;
      }
      cnt++;
    }
  }
  cout << "Yes\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
}
