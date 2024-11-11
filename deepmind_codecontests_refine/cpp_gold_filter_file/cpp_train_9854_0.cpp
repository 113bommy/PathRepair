#include <bits/stdc++.h>
using namespace std;
void setIO(string str, bool dbg) {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  if (!dbg) {
    freopen((str + ".in").c_str(), "r", stdin);
    freopen((str + ".out").c_str(), "w", stdout);
  }
}
const int MAX = 1e5 + 5;
const int LEN = 3e0 + 1;
const int LVL = 2e1 + 0;
const long long int MOD = 1e9 + 7;
const long long int INF = 9e17;
int xyz = 1;
int n, c;
long long int arr[MAX];
long long int sum[MAX];
long long int dps[MAX];
long long int get(int r, int l) { return sum[r] - sum[l]; }
void run() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) sum[i] = arr[i] + sum[i - 1];
  multiset<int> cur;
  for (int i = 1; i <= n; i++) {
    if (i > 0) cur.insert(arr[i]);
    if (i > c) cur.erase(cur.find(arr[i - c]));
    dps[i] = INF;
    if (i >= 1) dps[i] = min(dps[i], arr[i] + dps[i - 1]);
    if (i >= c) dps[i] = min(dps[i], dps[i - c] + get(i, i - c) - *cur.begin());
  }
  cout << dps[n] << "\n";
}
int main() {
  setIO("", 1);
  while (xyz--) run();
  return 0;
}
