#include <bits/stdc++.h>
using namespace std;
int num[200000 + 5];
int main() {
  int i, j, k, n, m;
  cin >> n;
  long long sum = 0;
  for (i = 0; i < n; i++) {
    cin >> num[i];
    sum += num[i];
  }
  long long ans = 0;
  sum++;
  sum /= 2;
  for (i = 0; i < n; i++) {
    ans += num[i];
    if (ans >= sum) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}
