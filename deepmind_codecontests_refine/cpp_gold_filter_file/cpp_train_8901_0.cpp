#include <bits/stdc++.h>
using namespace std;
long long int minn(long long int a, long long int b) {
  if (a > b) return b;
  return a;
}
long long int maxx2(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int maxx(long long int a, long long int b, long long int c) {
  return maxx2(a, maxx2(b, c));
}
long long int gcdd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcdd(b, a % b);
}
long long int dsum(long long int n) {
  long long int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
long long int poww(long long int a, long long int b) {
  if (b <= 0) return 1;
  if (b == 1)
    return a;
  else
    return poww(a, b / 2) * poww(a, b / 2) * poww(a, b % 2);
}
string substr1(string s, long long int i, long long int j) {
  string r = s.substr(i, j - i + 1);
  return r;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b;
  cin >> a >> b;
  long long int ans = 0, t[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  for (long long int i = a; i < b + 1; i++) {
    long long int j = i;
    while (j > 0) {
      ans += t[j % 10];
      j /= 10;
    }
  }
  cout << ans << endl;
  return 0;
}
