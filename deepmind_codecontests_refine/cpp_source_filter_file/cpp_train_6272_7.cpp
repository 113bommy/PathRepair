#include <bits/stdc++.h>
using namespace std;
const unsigned seed =
    std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rnd(seed);
const int MOD = 998244353;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> s(k);
  vector<bool> used(n + 1, false);
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    for (int j = 0; j < c; j++) {
      int t;
      cin >> t;
      used[t] = true;
      s[i].push_back(t);
    }
  }
  int a = 0;
  int b = k - 1;
  vector<int> res(k, -1);
  int maxA = -1;
  int lasta = 1;
  int lastb = -1;
  while (a <= b) {
    vector<int> nums;
    for (int i = a; i <= b; i++) {
      for (int t : s[i]) nums.push_back(t);
    }
    cout << "? " << nums.size();
    for (int t : nums) cout << " " << t;
    cout << endl;
    int r;
    cin >> r;
    if (maxA == -1) {
      maxA = r;
      lasta = a;
      lastb = b;
      b = (a + b) / 2;
    } else {
      if (maxA == r) {
        lasta = a;
        lastb = b;
        b = (a + b) / 2;
      } else {
        if (a == lasta) {
          lasta = b + 1;
        } else {
          lastb = a - 1;
        }
        b = (lasta + lastb) / 2;
        a = lasta;
      }
    }
    if (lasta == lastb) break;
  }
  vector<int> nums;
  for (int i = 0; i < k; i++) {
    if (i == lasta) continue;
    for (int t : s[i]) nums.push_back(t);
  }
  for (int i = 1; i <= n; i++)
    if (!used[i]) nums.push_back(i);
  cout << "? " << nums.size();
  for (int t : nums) cout << " " << t;
  cout << endl;
  int r;
  cin >> r;
  res[lasta] = r;
  for (int i = 0; i < k; i++) {
    if (i != lasta) res[i] = max(r, lasta);
  }
  cout << "!";
  for (int t : res) cout << " " << t;
  cout << endl;
  string resp;
  cin >> resp;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  int T = 1;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  cout.flush();
  return 0;
}
