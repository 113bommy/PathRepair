#include <bits/stdc++.h>
using namespace std;
int n, res = 999999999, tr = 0;
long long arr[8];
vector<long long> v;
map<long long, int> m;
void dfs(int dep) {
  if (dep == n) {
    int c = 0;
    for (int i = 0; i < v.size(); i++) c += m[v[i]];
    res = min(res, c + (tr > 1));
    return;
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i] % arr[dep] == 0) {
      v[i] /= arr[dep];
      if (m[arr[dep]] != 1) v.push_back(arr[dep]);
      dfs(dep + 1);
      if (m[arr[dep]] != 1) v.pop_back();
      v[i] *= arr[dep];
    }
  }
  if (m[arr[dep]] != 1) v.push_back(arr[dep]);
  tr++;
  dfs(dep + 1);
  tr--;
  if (m[arr[dep]] != 1) v.pop_back();
}
int count(long long a) {
  if (a == 1) return 0;
  for (long long i = 2; i * i <= a; i++)
    if (a % i == 0) return 1 + count(a / i);
  return 1;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    for (long long j = 1; j * j <= arr[i]; j++)
      if (arr[i] % j == 0) {
        m[j] = count(j);
        m[arr[i] / j] = count(arr[i] / j);
      }
  }
  m[1] = 0;
  sort(arr, arr + n, greater<long long>());
  dfs(0);
  cout << res + n << endl;
}
