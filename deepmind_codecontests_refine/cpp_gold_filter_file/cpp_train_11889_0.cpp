#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
long long vis[200005];
long long arr[200005];
void dfs(long long curr, vector<long long>& temp) {
  if (vis[curr] == 1) {
    return;
  }
  vis[curr] = 1;
  temp.push_back(curr);
  dfs(arr[curr - 1], temp);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    map<long long, long long> mp;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0) {
        vector<long long> temp;
        dfs(i, temp);
        for (int i = 0; i < (long long)temp.size(); i++) {
          mp[temp[i]] = temp.size();
        }
        temp.clear();
      }
    }
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
      cout << itr->second << " ";
    }
    cout << "\n";
  }
}
