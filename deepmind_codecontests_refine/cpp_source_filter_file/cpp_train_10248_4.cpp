#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
vector<long long> v;
void dfs(long long m) {
  if (m > 1e9) return;
  v.push_back(m);
  dfs(m * 10 + 4);
  dfs(m * 10 + 7);
}
int arr[100000], cnt[100000], ar[100000], x, m, c, n, val = 0;
int main() {
  fast();
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> x;
    arr[x] = 1;
  }
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 0)
      val += ar[i];
    else
      ar[c++] = ar[i];
  }
  sort(ar, ar + c);
  reverse(ar, ar + c);
  for (int i = 0; i < c; i++) {
    if (val > ar[i])
      val *= 2;
    else
      val += ar[i];
  }
  cout << val;
}
