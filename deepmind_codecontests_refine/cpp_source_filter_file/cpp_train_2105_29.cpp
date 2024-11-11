#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, sum = 0, count = 0, x = 0, y = 0;
  cin >> n;
  string a;
  cin >> a;
  for (long long int i = 0; i < n; i++) {
    if (a[i] == 'L') {
      count++;
    } else
      sum++;
  }
  if (count == 0) {
    cout << sum;
  } else if (sum == 0) {
    cout << count;
  } else {
    cout << count + sum + 1;
  }
}
