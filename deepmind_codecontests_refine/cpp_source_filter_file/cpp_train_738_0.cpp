#include <bits/stdc++.h>
using namespace std;
vector<bool> table(30001, 1);
vector<long long> arr;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (long long i = 0; i < 30001; i++) {
    if (i == 0 || i == 1)
      table[i] = 0;
    else if (table[i]) {
      arr.push_back(i);
      for (long long j = i * i; j < 30001; j += i) {
        if (table[j]) table[j] = 0;
      }
    }
  }
  long long n, ans;
  bool prime;
  while (cin >> n) {
    if (n < 30001 && table[n]) {
      cout << 1 << endl;
      continue;
    }
    ans = 0;
    while (n > 1) {
      if (n % 2 == 0) {
        ans += n / 2;
        break;
      }
      prime = 1;
      for (long long i = 1; i < arr.size() && arr[i] <= n; i++) {
        if (n % arr[i] == 0) {
          ans++;
          prime = 0;
          n -= arr[i];
          break;
        }
      }
      if (prime) {
        ans++;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
