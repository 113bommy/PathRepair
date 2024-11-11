#include <bits/stdc++.h>
using namespace std;
const int MX = 200000 + 5;
int T[4 * MX];
void up(int p, int l, int h, int x, int vl) {
  if (l == h) {
    T[p] += vl;
    return;
  }
  int m = (l + h) / 2;
  if (x <= m)
    up(2 * p, l, m, x, vl);
  else
    up(2 * p + 1, m + 1, h, x, vl);
  T[p] = T[2 * p] + T[2 * p + 1];
}
int Q(int p, int l, int h, int x, int y) {
  if (h < x || l > y) return 0;
  if (l >= x && h <= y) return T[p];
  int m = (l + h) / 2;
  return Q(2 * p, l, m, x, y) + Q(2 * p + 1, m + 1, h, x, y);
}
vector<long long> pq[MX];
priority_queue<long long> pq1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q, cs = 1, n, x, y;
  cin >> q;
  while (q--) {
    cin >> n;
    set<long long> st;
    set<long long>::iterator it;
    long long sm = 0, al = 0;
    for (int i = 1; i <= n; i++) {
      cin >> x >> y;
      if (!x) al++;
      pq[x].push_back(y);
      st.insert(-x);
      up(1, 1, MX, x, 1);
    }
    for (it = st.begin(); it != st.end(); it++) {
      int x = -*it;
      while (pq[x].size()) {
        pq1.push(-pq[x].back());
        pq[x].pop_back();
      }
      int r = Q(1, 1, MX, 1, x - 1);
      while (al + r < x) {
        al++;
        sm += -pq1.top();
        pq1.pop();
      }
      r = Q(1, 1, MX, x, x);
      up(1, 1, MX, x, -r);
    }
    cout << sm << endl;
    while (pq1.size()) pq1.pop();
  }
  return 0;
}
