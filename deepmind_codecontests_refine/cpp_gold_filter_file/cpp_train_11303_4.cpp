#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int l = s.length();
  long long ans = 0, power = 1;
  int i = l - 1;
  while (i >= 0) {
    int temp_i = i;
    long long p = 10;
    long long num = s[i--] - '0';
    int d = s[i] - '0';
    while (i >= 0 && num + d * p < n && num + d * p >= 0) {
      num = num + d * p;
      p *= 10;
      d = s[--i] - '0';
    }
    if (num == 0) {
      i = temp_i - 1;
    } else {
      while (s[i + 1] == '0') i++;
    }
    ans += num * power;
    power *= n;
  }
  cout << ans;
  return 0;
}
