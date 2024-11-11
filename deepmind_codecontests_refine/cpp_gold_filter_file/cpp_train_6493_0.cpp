#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, sum;
  cin >> n;
  sum = n;
  for (int i = 2; i <= n; i++) {
    sum += (n - i) * i + 1;
  }
  cout << sum << endl;
  return 0;
}
