#include <bits/stdc++.h>
using namespace std;
long long n, a, b, i;
long long h[2001];
bool cmp(int a, int b) { return a < b; }
int main() {
  cin >> n >> a >> b;
  for (i = 1; i <= n; i++) cin >> h[i];
  sort(h + 1, h + n + 1, cmp);
  cout << h[b + 1] - h[b];
  return 0;
}
