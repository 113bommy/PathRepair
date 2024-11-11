#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, k, v[N];
bool cmp(int a, int b) { return a > b; }
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> v[i];
  sort(v + 1, v + n + 1, cmp);
  cout << v[k];
  return 0;
}
