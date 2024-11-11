#include <bits/stdc++.h>
using namespace std;
long long i, b, t, k, n, m;
long long parent[100001];
long long arr[100001];
long long mass[100001];
long long p(long long a) {
  if (parent[a] == a) return a;
  return parent[a] = p(parent[a]);
}
void dsu(long long l, long long r) {
  l = p(l);
  r = p(r);
  if (l == r) return;
  parent[l] = r;
}
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
    parent[i] = i;
  }
  for (i = 1; i <= n; i++) {
    cin >> mass[i];
  }
  for (i = 1; i <= n; i++) {
    if (i + mass[i] <= n) dsu(i, i + mass[i]);
    if (i - mass[i] < 1) dsu(i, i - mass[i]);
  }
  for (i = 1; i <= n; i++) {
    p(i);
    p(arr[i]);
    if (parent[i] != parent[arr[i]]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
