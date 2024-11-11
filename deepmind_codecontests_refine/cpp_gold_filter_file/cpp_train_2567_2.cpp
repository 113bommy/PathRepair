#include <bits/stdc++.h>
using namespace std;
void read(vector<int>& v) {
  int n = v.size();
  for (int i = 0; i < n; i++) cin >> v[i];
}
void display(vector<int>& v) {
  int n = v.size();
  for (int i = 0; i < n; i++) cout << v[i] << " ";
  cout << "\n";
}
int not_to_visit;
long long comb(long long n) {
  if (n < 2) return (0);
  if (n == 2)
    return (1);
  else {
    long long ans = 0;
    ans = ans + (n * (n - 1));
    ans = ans / 2;
    return (ans);
  }
}
pair<long long, long long> dfs(vector<int> arr[], int curr, int prev) {
  pair<long long, long long> p, temp;
  p.first = 1;
  p.second = 0;
  if (curr == not_to_visit) {
    p.second = 1;
    return (p);
  }
  for (auto i : arr[curr]) {
    if (i == prev) continue;
    temp = dfs(arr, i, curr);
    if (temp.second == 0) {
      p.first = p.first + temp.first;
    } else {
      p.second = 1;
    }
  }
  return (p);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  while (t--) {
    long long n, x, y;
    cin >> n >> x >> y;
    vector<int> arr[n + 1];
    int a, b;
    for (int i = 1; i < n; i++) {
      cin >> a >> b;
      arr[a].push_back(b);
      arr[b].push_back(a);
    }
    long long nx, ny, nz;
    not_to_visit = y;
    nx = (dfs(arr, x, 0).first);
    not_to_visit = x;
    ny = (dfs(arr, y, 0).first);
    nz = n - (nx + ny);
    long long ans = 0;
    ans = ans + 2 * ((nx * nz) + (nz * ny)) + (nx * ny);
    ans = ans + 2 * (comb(nx) + comb(ny) + comb(nz));
    cout << ans << "\n";
  }
}
