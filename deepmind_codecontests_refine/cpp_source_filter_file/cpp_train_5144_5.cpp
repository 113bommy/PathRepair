#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int row[n];
  for (int i = 0; i < n; i++) cin >> row[i];
  sort(row, row + n);
  int i = 0;
  int sum = 0;
  while (row[i] < 0) sum += abs(row[i++]);
  cout << sum << endl;
  return 0;
}
