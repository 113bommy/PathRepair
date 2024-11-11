#include <bits/stdc++.h>
using namespace std;
long long Min(string s) {
  long long min = s[0] - '0';
  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - '0';
    if (c < min) min = c;
  }
  return min;
}
long long Max(string s) {
  long long max = 0;
  for (int i = 0; i < s.size(); i++) {
    int c = s[i] - '0';
    if (c > max) max = c;
  }
  return max;
}
int main() {
  string num;
  long long n, t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    cin >> num >> n;
    long long x = stoll(num);
    for (int i = 1; i < n; i++) {
      x += Min(num) * Max(num);
      num = to_string(x);
      if (Min(num) == 0) break;
    }
    printf("%lld \n", x);
  }
}
