#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int inf = 1e9 + 5;
int n;
unordered_map<int, unordered_map<int, int>> dud;
void upd(int x, long long val, int k) {
  while (x <= inf) {
    dud[x][k] += val;
    x += x & (-x);
  }
}
long long query(int x, int k) {
  long long sum = 0;
  while (x > 0) {
    sum += dud[x][k];
    x -= x & (-x);
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int tip, t, x;
    cin >> tip >> t >> x;
    if (tip == 1) upd(t, 1, x);
    if (tip == 2) upd(t, -1, x);
    if (tip == 3) cout << query(t, x) << endl;
  }
  return 0;
}
