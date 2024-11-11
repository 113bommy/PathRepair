#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  long long sum = 0, cur, d;
  cin >> d;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> cur;
    sum += d - cur;
  };
  cout << sum - d + cur << endl;
  return 0;
}
