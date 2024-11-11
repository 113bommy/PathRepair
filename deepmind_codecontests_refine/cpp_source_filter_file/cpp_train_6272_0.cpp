#include <bits/stdc++.h>
std::mt19937 rng(
    (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
int cnt = 0;
int ask(vector<int> &r) {
  cnt++;
  assert(cnt < 13);
  int sz = r.size();
  cout << "? " << sz << " ";
  for (auto &x : r) {
    cout << x + 1 << " ";
  }
  cout << endl;
  int res;
  cin >> res;
  return res;
}
void solve() {
  cnt = 0;
  int n, k;
  cin >> n >> k;
  vector<int> group(n);
  for (long long int i = 0; i < k; i++) {
    int sz;
    cin >> sz;
    for (long long int j = 0; j < sz; j++) {
      int m;
      cin >> m;
      m--;
      group[m] = i;
    }
  }
  vector<int> ind(n);
  iota(ind.begin(), ind.end(), 0);
  int mx = ask(ind);
  int low = -1, high = n - 1;
  while (low + 1 < high) {
    int mid = (low + high) / 2;
    1;
    vector<int> v(ind.begin(), ind.begin() + mid + 1);
    int res = ask(v);
    if (res == mx) {
      high = mid;
    } else {
      low = mid;
    }
  }
  vector<int> nw, res(k);
  for (long long int i = 0; i < k; i++) {
    if (i != group[high]) res[i] = mx;
  }
  for (long long int i = 0; i < n; i++) {
    if (group[i] != group[high]) {
      nw.push_back(i);
    }
  }
  int oth = ask(nw);
  res[group[high]] = oth;
  cout << "! ";
  for (long long int i = 0; i < k; i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  string s;
  cin >> s;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ttt;
  ttt = 1;
  cin >> ttt;
  while (ttt--) solve();
}
