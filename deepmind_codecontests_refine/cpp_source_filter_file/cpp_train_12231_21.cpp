#include <bits/stdc++.h>
using namespace std;
const long long MXN = 2e5 + 7;
const long long MOD = 1e9 + 7;
void allday() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void relax() {
  freopen("txt.in", "w", stdin);
  freopen("txt,out", "r", stdout);
}
int n, a[MXN], f[MXN], ans[MXN];
vector<pair<int, int>> v;
void add(int id, int val) {
  while (id <= n) {
    f[id] += val;
    id = (id | (id + 1));
  }
}
long long sum(int id) {
  long long sum = 0;
  while (id > 0) {
    sum += f[id];
    id = (id & (id + 1)) - 1;
  }
  return sum;
}
int main() {
  allday();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    v.push_back({a, i});
  }
  sort(v.begin(), v.end());
  for (pair<int, int> p : v) {
    int i = p.second;
    for (int k = 1; k * (i - 1) + 2 <= n && k + 2 <= n; k++) {
      int L = (k * (i - 1) + 2);
      int R = min((k * i + 1), n);
      ans[k] += sum(R) - sum(L - 1);
    }
    add(i, 1);
  }
  for (int i = 1; i < n; i++) {
    cout << ans[i] << ' ';
  }
}
