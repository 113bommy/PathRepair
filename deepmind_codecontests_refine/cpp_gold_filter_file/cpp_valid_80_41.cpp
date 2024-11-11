#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
long long n;
string s;
void speed() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void sol() {
  long long flag = 0;
  for (long long i = 0; i < s.size(); i++)
    if (s[i] == '0') {
      if (i >= n / 2)
        printf("1 %lld 1 %lld\n", i + 1, i);
      else if (n - i > n / 2)
        printf("%lld %lld %lld %lld\n", i + 1, n, i + 2, n);
      return;
    }
  printf("1 %lld 2 %lld\n", n - 1, n);
  return;
}
int main() {
  speed();
  long long tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> s;
    sol();
  }
  return 0;
}
