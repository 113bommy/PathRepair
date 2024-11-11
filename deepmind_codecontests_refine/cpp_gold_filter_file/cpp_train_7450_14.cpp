#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, cnt = 1;
  cin >> n >> k;
  while (k > 0) {
    if (k & 1 != 0) break;
    cnt++;
    k = k >> 1;
  }
  cout << cnt;
  return 0;
}
