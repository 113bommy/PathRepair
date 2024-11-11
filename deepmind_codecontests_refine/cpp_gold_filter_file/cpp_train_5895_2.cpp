#include <bits/stdc++.h>
using namespace std;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const double EPS = 1e-5;
struct query {
  int t, l, r;
};
int n, q, m;
vector<int> num;
vector<query> qs;
int getNum(int x) {
  for (int i = 0; i < q; i++)
    if (x >= qs[i].l && x <= qs[i].r) {
      if (qs[i].t == 1)
        x = x == qs[i].l ? qs[i].r : x - 1;
      else
        x = qs[i].r - (x - qs[i].l);
    }
  return x;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> q >> m;
  num.resize(n);
  for (int i = 0; i < n; i++) cin >> num[i];
  qs.resize(q);
  for (int i = 0; i < q; i++) {
    cin >> qs[i].t >> qs[i].l >> qs[i].r;
    qs[i].l--, qs[i].r--;
  }
  reverse(qs.begin(), qs.end());
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    x--;
    cout << num[getNum(x)] << " \n"[i == m - 1];
  }
  cin.ignore(), cin.get();
}
