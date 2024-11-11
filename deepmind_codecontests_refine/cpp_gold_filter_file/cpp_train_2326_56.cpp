#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  int d, n;
  cin >> d >> n;
  vector<int> days(n);
  for (int i = 0; i < n; i++) cin >> days[i];
  int count = 0;
  for (int i = 1; i < n; i++) count += d - days[i - 1];
  cout << count << '\n';
  return 0;
}
