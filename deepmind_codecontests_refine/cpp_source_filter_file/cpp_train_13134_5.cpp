#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9) + 7;
const long long int MOD64 = (long long int)(1e18) + 7;
const int INF = 0x7fffffff;
const long long int INF64 = 0x7fffffffffffffff;
const int N = 3e5 + 10;
long long int a[N];
long long int b[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, p, k;
  cin >> n >> p >> k;
  for (int i = int(0); i < int(n); i++) {
    cin >> a[i];
    long long int temp = a[i];
    temp = temp * temp % p;
    temp = temp * temp % p;
    temp = (temp - k * a[i]) % p;
    temp = (temp + p) % p;
    b[i] = temp;
  }
  sort(b, b + n);
  long long int ans = 0;
  long long int cnt = b[0];
  long long int num = 1;
  for (int i = int(1); i < int(n); i++) {
    while (b[i] == cnt) {
      i++;
      num++;
    }
    ans += (num - 1) * num / 2;
    cnt = b[i];
    num = 1;
  }
  cout << ans << endl;
  return 0;
}
