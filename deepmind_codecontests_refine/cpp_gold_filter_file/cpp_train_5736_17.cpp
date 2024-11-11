#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<int> V(200002);
ll getCount(int m) {
  unordered_map<int, ll> ls, ps;
  int s = 0;
  ll sans = 0, ans = 0;
  ls[0] = 1;
  ls[-1] = 0;
  for (int i = 0; i < n; ++i) {
    if (V[i] >= m) {
      sans += ls[s];
      s++;
    } else {
      s--;
      sans -= ls[s];
    }
    if (ls.count(s) == 0)
      ls[s] = 1;
    else
      ls[s]++;
    ans += sans;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> V[i];
  cout << getCount(k) - getCount(k + 1) << (char)10;
}
