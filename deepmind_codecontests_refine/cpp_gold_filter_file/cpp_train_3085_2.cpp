#include <bits/stdc++.h>
using namespace std;
long long a[100001];
int p[100001];
int n, m;
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
int main() {
  long long result = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i], p[i] = i;
  while (m--) {
    int x, y;
    cin >> x >> y;
    x = find(x);
    y = find(y);
    if (x == y) continue;
    if (a[x] > a[y])
      p[x] = y;
    else
      p[y] = x;
  }
  for (int i = 1; i <= n; i++)
    if (p[i] == i) result += a[i];
  cout << result << endl;
}
