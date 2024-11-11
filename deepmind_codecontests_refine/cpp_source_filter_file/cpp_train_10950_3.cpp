#include <bits/stdc++.h>
using namespace std;
const int QQ = 3e5 + 10;
const int maxN = 3e5 + 100;
const int maxM = 3e5 + 10;
const long long oo = 1e15;
const int module = 1e9 + 7;
const long double du = 1e-9;
void doc() {
  freopen(
      "solve"
      ".inp",
      "r", stdin);
  freopen(
      "solve"
      ".out",
      "w", stdout);
}
void solve() {
  int n, k;
  cin >> n >> k;
  int a[n];
  vector<int> B;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    B.push_back(a[i]);
  }
  sort(B.begin(), B.end());
  B.resize(unique(B.begin(), B.end()) - B.begin());
  int D[n + 1];
  memset(D, -1, sizeof(D));
  int L = 0, R = -1;
  int Pos = 0;
  int tmp[n + 1];
  for (int i = 0; i < n; i++) {
    int id = lower_bound(B.begin(), B.end(), a[i]) - B.begin();
    if (D[id] != -1) continue;
    if (R - L + 1 >= k) {
      int pre_id = lower_bound(B.begin(), B.end(), tmp[L]) - B.begin();
      D[pre_id] -= 1;
      L++;
    }
    D[id] = Pos;
    Pos++;
    R++;
    tmp[R] = a[i];
  }
  vector<int> Res;
  for (int i = 0; i < (int)B.size(); i++) {
    if (D[i] != -1) Res.push_back(i);
  }
  sort(Res.begin(), Res.end(), [&](int i, int j) { return D[i] < D[j]; });
  cout << (int)Res.size() << '\n';
  for (int x : Res) cout << x + 1 << ' ';
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}
