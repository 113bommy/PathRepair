#include <bits/stdc++.h>
using namespace std;
long long n, m, sum, p, arr[10001];
int main() {
  cin >> n;
  int x = 1;
  for (int i = 0; i < 10000; i++) {
    p = i;
    x += p;
    if (x > n) x %= n;
    if (x == 0) x = 1;
    if (arr[x] != 1) {
      arr[x] = 1;
      sum++;
    }
  }
  if (sum == n)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
