#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<long long> vec;
inline int getid(int x) {
  return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
}
bool tag[maxn][60];
int id[maxn];
int cnt[maxn];
long long sum[maxn];
long long arr[maxn], brr[maxn];
bool vis[maxn];
set<int> ishave;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    vec.push_back(arr[i]);
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  for (int i = 0; i < n; ++i) {
    cin >> brr[i];
  }
  for (int i = 0; i < n; ++i) {
    int id = getid(arr[i]);
    cnt[id]++;
    sum[id] += brr[i];
    for (int j = 0; j < 60; ++j) {
      if ((arr[i] >> j) & 1) {
        tag[id][j] = true;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < vec.size(); ++i) {
    int id = getid(vec[i]);
    if (cnt[id] > 1) {
      vis[id] = true;
      ans += sum[id];
      ishave.insert(id);
    }
  }
  for (int i = 0; i < vec.size(); ++i) {
    int id = getid(vec[i]);
    if (vis[id]) continue;
    for (auto k : ishave) {
      bool isok = true;
      for (int j = 0; j < 60; ++j) {
        if (tag[id][j] && !tag[k][j]) {
          isok = false;
          break;
        }
      }
      if (isok) {
        ans += sum[id];
        break;
      }
    }
  }
  if (n == 1) {
    cout << 0 << endl;
  } else
    cout << ans << endl;
  return 0;
}
