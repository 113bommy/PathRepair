#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
vector<int> ans;
int cnt[1000010];
int tmp[1000010];
int a[1000010], f[1000010];
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] > m) continue;
    tmp[a[i]]++;
  }
  for (int i = 2; i * i <= 1e6; i++) {
    if (f[i]) continue;
    prime.push_back(i);
    for (int j = i * i; j <= 1e6; j += i) {
      f[j] = i;
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; i * j <= m; j++) {
      cnt[i * j] += tmp[i];
    }
  }
  int _max = 0;
  int id = 0;
  for (int i = 1; i <= m; i++) {
    if (cnt[i] > _max) _max = cnt[i], id = i;
  }
  for (int i = 1; i <= n; i++) {
    if (id % a[i]) continue;
    ans.push_back(i);
  }
  if (id == 0) {
    ans.clear();
    id = 1;
  }
  cout << id << " " << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
