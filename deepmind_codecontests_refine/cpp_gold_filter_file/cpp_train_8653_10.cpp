#include <bits/stdc++.h>
using namespace std;
long long n, s;
int a[100010];
int size[100010], fa[100010], deep[100010], indeep[100010];
int main() {
  cin >> n >> s;
  if (s < (2 * n - 1) || s > n * (n + 1) / 2) {
    puts("No");
    return 0;
  }
  puts("Yes");
  long long k, dep, sumdep;
  for (k = 1; k <= n - 1; k++) {
    long long cnt = 1, tmp = 0, now = n, sizenow = 1;
    while (now >= sizenow) {
      now -= sizenow;
      tmp += sizenow * cnt;
      sizenow *= k;
      cnt++;
    }
    tmp += now * cnt;
    dep = cnt;
    sumdep = tmp;
    if (tmp <= s) break;
  }
  if (k == 1) {
    for (int i = 2; i <= n; i++) cout << i - 1 << " ";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    fa[i] = (i + k - 2) / k;
    deep[i] = deep[fa[i]] + 1;
    size[fa[i]]++;
  }
  int now = n, depnow = deep[now];
  int ttmp = now;
  while (ttmp) {
    indeep[deep[ttmp]] = ttmp;
    ttmp /= k;
  }
  queue<int> q;
  for (int i = n - 1; i >= 1; i--) {
    if (size[i] == 0) q.push(i);
  }
  while (!q.empty() && sumdep < s) {
    int v = q.front();
    if (sumdep + depnow - deep[v] + 1 > s) {
      fa[v] = indeep[deep[v] + s - sumdep - 1];
      break;
    }
    sumdep += depnow - deep[v] + 1;
    size[fa[v]]--;
    if (size[fa[v]] == 0) q.push(fa[v]);
    size[now]++;
    depnow++;
    indeep[depnow] = v;
    fa[v] = now;
    now = v;
    q.pop();
  }
  for (int i = 2; i <= n; i++) {
    cout << fa[i] << " ";
  }
}
