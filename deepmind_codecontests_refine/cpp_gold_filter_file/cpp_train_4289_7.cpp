#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
vector<long long> luck;
void dfs(long long a, long long len) {
  if (len > 11) return;
  if (a) luck.push_back(a);
  dfs(a * 10 + 4, len + 1);
  dfs(a * 10 + 7, len + 1);
}
long long fact[30];
long long arr[50];
void find(long long n, long long x) {
  vector<long long> v;
  for (int i = 0; i < n; i++) v.push_back(i + 1);
  for (int i = 0; i < n; i++) {
    long long y = x / (fact[n - i - 1]);
    arr[i] = v[y];
    v.erase(v.begin() + y);
    x %= (fact[n - i - 1]);
  }
}
bool isl(long long a) {
  if (!a) return 0;
  while (a) {
    int g = a % 10;
    if (g != 4 && g != 7) return 0;
    a /= 10;
  }
  return true;
}
int main() {
  dfs(0, 0);
  sort(luck.begin(), luck.end());
  long long n, k;
  cin >> n >> k;
  fact[0] = 1;
  for (int i = 1; i < 30; i++) fact[i] = fact[i - 1] * i;
  if (n <= 20 && k > fact[n]) {
    cout << -1 << endl;
    return 0;
  }
  long long len = min(20ll, n);
  find(len, k - 1);
  long long p = n - len;
  long long ind = upper_bound(luck.begin(), luck.end(), p) - luck.begin();
  long long ans = ind;
  for (int i = 0; i < len; i++) {
    arr[i] += p;
    if (isl(arr[i]) && isl(i + p + 1)) ans++;
  }
  cout << ans << endl;
}
