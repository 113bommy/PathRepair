#include <bits/stdc++.h>
using namespace std;
vector<long long> x, v;
int idX(int val) { return (lower_bound(x.begin(), x.end(), val) - x.begin()); }
int idV(int val) { return (lower_bound(v.begin(), v.end(), val) - v.begin()); }
struct FenwickTree {
  vector<long long> bit;
  int n;
  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }
  long long sum(int r) {
    long long ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }
  long long sum(int l, int r) { return sum(r) - sum(l - 1); }
  void upd(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
  }
};
void nikal_pehli_fursat_mai() {
  int n;
  cin >> n;
  vector<array<long long, 2>> arr(n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i][0];
    x.push_back(arr[i][0]);
  }
  for (int i = 0; i < n; i++) {
    cin >> arr[i][1];
    v.push_back(abs(arr[i][1]));
  }
  sort(v.begin(), v.end());
  sort(x.begin(), x.end());
  sort(arr.begin(), arr.end());
  FenwickTree pos(n), neg(n), zero(n), cntp(n), cntn(n), cntz(n);
  for (int i = 0; i < n; i++) {
    int id = idV(abs(arr[i][1]));
    if (arr[i][1] > 0) {
      cntp.upd(id, 1);
      pos.upd(id, arr[i][0]);
    } else if (arr[i][1] < 0) {
      cntn.upd(id, 1);
      neg.upd(id, arr[i][0]);
    } else {
      cntz.upd(id, 1);
      zero.upd(id, arr[i][0]);
    }
  }
  for (int i = 0; i < n; i++) {
    int id = idV(abs(arr[i][1]));
    if (arr[i][1] > 0) {
      ans += pos.sum(id, n - 1) - cntp.sum(id, n - 1) * arr[i][0];
      cntp.upd(id, -1);
      pos.upd(id, -arr[i][0]);
    } else if (arr[i][1] < 0) {
      ans += pos.sum(0, n - 1) - cntp.sum(0, n - 1) * arr[i][0];
      ans += zero.sum(0, n - 1) - cntz.sum(0, n - 1) * arr[i][0];
      ans += neg.sum(0, id) - cntn.sum(0, id) * arr[i][0];
      cntn.upd(id, -1);
      neg.upd(id, -arr[i][0]);
    } else {
      ans += pos.sum(id, n - 1) - cntp.sum(id, n - 1) * arr[i][0];
      ans += zero.sum(0, n - 1) - cntz.sum(0, n - 1) * arr[i][0];
      cntz.upd(id, -1);
      zero.upd(id, -arr[i][0]);
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  while (tc--) {
    nikal_pehli_fursat_mai();
  }
}
