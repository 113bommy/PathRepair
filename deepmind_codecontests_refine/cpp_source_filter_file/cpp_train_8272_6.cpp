#include <bits/stdc++.h>
using namespace std;
long long n, k, prt[((long long)1001 * 1000)], f[((long long)1001 * 1000)],
    strt[((long long)1001 * 1000)], fnsh[((long long)1001 * 1000)], num = 1;
string s;
vector<long long> child[((long long)1001 * 1000)];
void dfs(long long x) {
  strt[x] = num++;
  for (int i = 0; i < child[x].size(); i++) dfs(child[x][i]);
  fnsh[x] = num;
}
int main() {
  cin >> n >> k >> s;
  for (int i = 2, j = 0; i < n; i++) {
    while (j && s[j] != s[i]) j = f[j];
    if (s[j] == s[i]) j++;
    f[i + 1] = j;
    child[j].push_back(i + 1);
  }
  for (int i = 1; i <= n; i++)
    if (!strt[i]) dfs(i);
  for (int i = 1; i * k <= n; i++) {
    bool flg = 1;
    for (int j = 2 * i; j <= k * i; j += i)
      if (strt[j] < strt[i] || strt[j] >= fnsh[i]) flg = 0;
    if (!flg) continue;
    long long l = i * k, r = min(n + 1, i * (k + 1) + 1);
    while (l < r - 1) {
      long long mid = l + r >> 1;
      if (strt[mid - i * k] <= strt[mid] && strt[mid] < fnsh[mid - i * k])
        l = mid;
      else
        r = mid;
    }
    prt[i * k - 1]++;
    prt[l]--;
  }
  for (int i = 0; i < n; i++) {
    if (i) prt[i] += prt[i - 1];
    cout << (prt[i] > 0);
  }
  return 0;
}
