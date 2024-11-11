#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> st(n, 0);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    ++st[a];
    ++st[b];
  }
  long long zle = 0;
  for (int i = 0; i < n; ++i) zle += st[i] * (n - 1 - st[i]);
  zle /= 2;
  long long wsz = n * (n - 1) * (n - 2) / 6;
  cout << wsz - zle;
  return 0;
}
