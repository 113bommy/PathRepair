#include <bits/stdc++.h>
using namespace std;
int n, k;
const int MAX_N = 200 * 1000 + 5;
long long int arrn[MAX_N];
long long int arre[MAX_N];
int arrc[MAX_N];
vector<int> q[MAX_N];
bool check(long long int g) {
  for (int i = 0; i < MAX_N; i++) {
    arrc[i] = 0;
    q[i].resize(0);
  }
  for (int i = 0; i < n; i++) {
    q[(int)min(arrn[i] / arre[i], (long long int)(MAX_N - 1))].push_back(i);
  }
  int s = 0;
  int cache = 1;
  while (s < k - 1) {
    if (q[s].size() > cache) {
      return false;
    }
    for (int i = 0; i < q[s].size(); i++) {
      if (cache <= 0) return false;
      cache--;
      int id = q[s][i];
      arrc[id]++;
      int nh =
          min((arrn[id] + g * arrc[id]) / arre[id], (long long int)(MAX_N - 1));
      while (nh <= s) {
        if (cache <= 0) return false;
        cache--;
        arrc[id]++;
        nh = min((arrn[id] + g * arrc[id]) / arre[id],
                 (long long int)(MAX_N - 1));
      }
      q[nh].push_back(id);
    }
    s++;
    cache++;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arrn[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> arre[i];
  }
  long long int res = -1;
  long long int mn = 0, mx = n * 1e7 + 5, md;
  while (mn <= mx) {
    md = (mn + mx) / 2;
    if (check(md)) {
      res = md;
      mx = md - 1;
    } else {
      mn = md + 1;
    }
  }
  cout << res << endl;
  return 0;
}
