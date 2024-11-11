#include <bits/stdc++.h>
using namespace std;
const int maxn = int(1e5) + 10;
int n, a[maxn], b[maxn];
long long moves[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  moves[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    int d = n - i - 1;
    int pos = floor(log(d) / log(2));
    moves[i + 1] = a[i] + moves[i];
    a[i + (1 << pos)] += a[i];
  }
  for (int i = 1; i < n; i++) cout << moves[i] << '\n';
  return 0;
}
