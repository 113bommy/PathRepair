#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007LL;
const int N = 2e5 + 10;
const long long Inf = 2242545357980376863LL;
const long long Log = 30;
vector<long long> V;
long long a[N], v[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  V.push_back(a[0]);
  for (int i = 1; i < n; i++)
    if (a[i] != a[i - 1]) V.push_back(a[i]);
  n = V.size();
  for (int i = 1; i < n; i++) {
    v[V[i]]--;
    v[V[i - 1]]--;
  }
  for (int i = 1; i + 1 < n; i++) {
    if (V[i - 1] != V[i + 1]) v[V[i]]++;
  }
  cout << min_element(v + 1, v + 1 + k) - v << '\n';
  return 0;
}
