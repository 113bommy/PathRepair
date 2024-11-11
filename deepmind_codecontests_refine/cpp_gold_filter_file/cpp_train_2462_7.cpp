#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 100000 + 10;
long long int a[maxn];
vector<long long int> v[maxn];
bool f[maxn];
void df(long long int k, long long int x) {
  f[k] = true;
  a[x]++;
  for (long long int i = 0; i < v[k].size(); i++)
    if (f[v[k][i]] == false) df(v[k][i], x + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  for (long long int i = 2; i <= n; i++) {
    long long int c;
    cin >> c;
    v[c].push_back(i);
    v[i].push_back(c);
  }
  df(1, 0);
  long long int res = 0;
  for (long long int i = 0; i <= n; i++) {
    if ((a[i] % 2) == 1) res++;
  }
  cout << res;
  return 0;
}
