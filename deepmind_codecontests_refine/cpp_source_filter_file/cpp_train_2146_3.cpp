#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, x, sum(0), cnt(0), prev(INT_MAX);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (i && x == prev)
      cnt++;
    else
      cnt = 1;
    prev = x;
    sum += cnt;
  }
  cout << sum;
  return 0;
}
