#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n, m;
int a[300005], b[300005], d[300005], cnt[300005];
vector<int> ve[300005];
void topsort(int a[], int b[]) {
  for (int i = 0; i < n; i++) ve[i].clear();
  for (int i = 0; i < m; i++) {
    ve[a[i]].push_back(b[i]);
    d[b[i]]++;
  }
  int num = n;
  queue<int> Q;
  for (int i = 0; i < n; i++) {
    if (!d[i]) {
      Q.push(i);
      num--;
    }
  }
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    if (Q.empty())
      cnt[now] += num;
    else if (Q.size() == 1) {
      int tmp = 1;
      for (int i = 0, y = Q.front(); i < ve[y].size(); i++) {
        tmp &= (d[ve[y][i]] > 1);
      }
      cnt[now] = num * tmp;
    }
    for (int i = 0; i < ve[now].size(); i++)
      if (!--d[ve[now][i]]) {
        Q.push(ve[now][i]);
        num--;
      }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  topsort(a, b);
  topsort(b, a);
  int ans = 0;
  for (int i = 0; i < n; i++) ans += (cnt[i] + 2 >= n);
  cout << ans << endl;
}
