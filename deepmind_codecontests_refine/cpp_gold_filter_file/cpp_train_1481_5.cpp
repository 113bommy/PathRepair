#include <bits/stdc++.h>
using namespace std;
long long int n, i, k, q, t, v[200010];
long long int check[200010], conta = 1, fine = 1 << 31 - 1;
void dfs(vector<long long int> p, long long int k, long long int tot) {
  if (!k) {
    if (tot < fine) fine = tot;
    return;
  }
  vector<long long int> u, z;
  bool zeri = false, uni = 0;
  for (int i = 0; i < p.size(); i++) {
    if (k & p[i])
      uni = 1;
    else
      zeri = 1;
  }
  if (!zeri || !uni) {
    for (int i = 0; i < p.size(); i++) z.push_back(p[i]);
    dfs(z, k >> 1, tot);
  } else {
    for (int i = 0; i < p.size(); i++) {
      if (k & p[i]) z.push_back(p[i]);
    }
    dfs(z, k >> 1, tot + k);
    for (int i = 0; i < p.size(); i++) {
      if (!(k & p[i])) u.push_back(p[i]);
    }
    dfs(u, k >> 1, tot + k);
  }
}
int main() {
  cin >> n;
  for (i = 0; i < n; i++) cin >> v[i];
  k = 1 << 30;
  vector<long long int> p;
  for (i = 0; i < n; i++) p.push_back(v[i]);
  dfs(p, k, 0);
  cout << fine;
}
