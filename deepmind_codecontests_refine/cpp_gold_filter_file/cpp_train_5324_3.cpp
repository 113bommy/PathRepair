#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 179;
int n, m, k, s;
int curr[N];
int needed[N];
int left123;
int arr[N];
bool can(int l, int r) { return r - l + 1 - k + l % k <= m - n * k; }
signed main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> k >> n >> s;
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < s; i++) {
    int a;
    cin >> a;
    if (needed[a] == 0) left123++;
    needed[a]++;
  }
  int R = -1;
  int L = 0;
  while (L < m) {
    while (left123 != 0 && R + 1 < m) {
      R++;
      curr[arr[R]]++;
      if (needed[arr[R]] == curr[arr[R]]) left123--;
    }
    if (can(L, R) && left123 == 0) {
      vector<int> good;
      for (int i = R; i >= L; i--) {
        if (needed[arr[i]]) {
          needed[arr[i]]--;
          good.push_back(i);
        }
      }
      reverse(good.begin(), good.end());
      int start = L;
      int end = good[good.size() - 1];
      vector<int> todel;
      int last = start;
      int gid = 0;
      while (end - start + 1 - todel.size() > k) {
        if (last == good[gid]) {
          last++;
          gid++;
          continue;
        } else if (last > good[gid]) {
          gid++;
          continue;
        } else {
          todel.push_back(last++);
        }
      }
      for (int i = 0; i < L % k; i++) {
        todel.push_back(i);
      }
      cout << todel.size() << endl;
      for (auto el : todel) cout << el + 1 << " ";
      cout << endl;
      return 0;
    }
    if (curr[arr[L]] == needed[arr[L]]) left123++;
    curr[arr[L]]--;
    L++;
  }
  cout << -1 << endl;
  return 0;
}
