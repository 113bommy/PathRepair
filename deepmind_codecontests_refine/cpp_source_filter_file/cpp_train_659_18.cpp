#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, k, n;
  cin >> y >> k >> n;
  int m = n - y;
  int temp = y % k;
  temp = k - temp;
  int count = 0;
  for (int i = temp; i <= m; i += 6) {
    cout << i << " ";
    count++;
  }
  if (count == 0) cout << "-1\n";
  return 0;
}
