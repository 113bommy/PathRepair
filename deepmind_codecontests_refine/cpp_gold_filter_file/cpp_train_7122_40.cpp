#include <bits/stdc++.h>
using namespace std;
int need[103 + 4];
int owes[103 + 4];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    owes[a] += c;
    need[b] += c;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (owes[i] <= need[i]) sum += need[i] - owes[i];
  }
  cout << sum << "\n";
}
