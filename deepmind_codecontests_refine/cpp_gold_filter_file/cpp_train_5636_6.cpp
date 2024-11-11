#include <bits/stdc++.h>
const int MAX = 5e5 + 9;
const int mod = 1e9 + 7;
using namespace std;
int trie[MAX][2];
int cnt, n;
int d(int n) {
  int res = 0;
  while (n) {
    res = res + (n % 10);
    n = n / 10;
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  long long arr[10] = {0};
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    arr[i % 9]++;
    ans = ans - n / i;
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      ans += arr[i % 9] * arr[j % 9] * arr[d(i * j) % 9];
    }
  }
  cout << ans << "\n";
}
