#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = 1e6 + 10;
const int INF = 0x3f3f3f3f;
long long casn, n, m, k;
long long num[maxn];
long long pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % 100;
    a = (a * a) % 100;
    b /= 2;
  }
  return ans;
}
int main() {
  cin >> n;
  cout << pow(5, n) << endl;
  return 0;
}
