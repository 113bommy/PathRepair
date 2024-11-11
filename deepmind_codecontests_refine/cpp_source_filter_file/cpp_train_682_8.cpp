#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long int> v;
  long long ar[101] = {0}, ar2[101] = {0};
  long long int i, j, temp, n, m, k, flag = 1, ma = 0, sum = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> temp;
    ar[temp] += 1;
  }
  for (i = 0; i < n; i++) {
    cin >> temp;
    ar2[temp] += 1;
  }
  for (i = 1; i < 10; i++) {
    if ((ar[i] + ar2[i]) % 2 != 0) {
      cout << -1;
      return 0;
    }
    if (ar[i] != ar2[i]) {
      sum += abs(ar[i] = ar2[i]) / 2;
    }
  }
  cout << sum;
  return 0;
}
