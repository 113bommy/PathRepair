#include <bits/stdc++.h>
using namespace std;
long long int bit[100009] = {0}, m = -1, n;
void update(long long int i, long long int val) {
  while (i < m + 3) {
    bit[i] = max(val, bit[i]);
    i += (i & (-i));
  }
}
long long int query(long long int i) {
  long long int sum = 0;
  while (i > 0) {
    sum = max(sum, bit[i]);
    i -= (i & (-i));
  }
  return sum;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  long long int i, x;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    m = max(m, x);
    update(x, query(x) + 1);
  }
  cout << query(m) << endl;
  return 0;
}
