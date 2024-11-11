#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  if (fopen("input.in", "r")) {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
  }
  int n;
  long double s;
  cin >> n >> s;
  int counts[100003];
  memset(counts + 1, 0, n + 2);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    counts[a]++;
    counts[b]++;
  }
  long double leaves = count(counts + 1, counts + n + 1, 1);
  cout << fixed << setprecision(12) << (long double)2 * (s / leaves) << endl;
}
