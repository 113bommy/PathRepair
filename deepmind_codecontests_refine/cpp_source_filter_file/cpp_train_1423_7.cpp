#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool visited[N];
int arr[N], comp[N], b[N], id, n, res[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  map<int, int> mp;
  for (auto i = 0; i < (long long)(n); i++) {
    cin >> arr[i];
    int x = abs(arr[i]);
    for (int j = 2; j * j <= x; j++)
      if (arr[i] % (j * j) == 0) arr[i] /= (j * j);
    if (!mp[arr[i]]) mp[arr[i]] = id++;
  }
  for (auto i = 0; i < (long long)(n); i++) comp[i] = mp[arr[i]];
  for (auto i = 0; i < (long long)(n); i++) {
    for (auto j = 0; j < (long long)(id); j++) visited[j] = false;
    int idx = 0;
    for (auto j = i; j < (long long)(n); j++) {
      if (arr[j] && !visited[comp[j]]) idx++;
      visited[comp[j]] = true;
      if (!idx)
        res[1]++;
      else
        res[idx]++;
    }
  }
  for (auto i = 1; i <= (long long)(n); i++) cout << res[i] << " ";
  return 0;
}
