#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
long long visited[1000001] = {0};
void solve() {
  long long a, b, c;
  long long sum = 0;
  long long count = 0;
  cin >> a >> b >> c;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
        long long num = i * j * k;
        count = 0;
        if (visited[num] == 0) {
          for (int x = 1; x <= sqrt(num); x++) {
            if (num % x == 0) {
              if (x * x == num)
                count += 1;
              else
                count += 2;
            }
          }
          visited[num] = count;
        }
        sum += visited[num];
        sum % 1073741824;
      }
    }
  }
  cout << sum << endl;
}
int main() {
  solve();
  return 0;
}
