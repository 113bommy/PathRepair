#include <bits/stdc++.h>
using namespace std;
long long Set(long long N, long long pos) { return N = N | (1 << pos); }
long long reset(long long N, long long pos) { return N = N & ~(1 << pos); }
bool check(long long N, long long pos) { return (bool)(N & (1 << pos)); }
void CI(long long &_x) { scanf("%d", &_x); }
void CO(long long &_x) { cout << _x; }
template <typename T>
void getarray(T a[], long long n) {
  for (long long i = 0; i < n; i++) cin >> a[i];
}
template <typename T>
void prLLIarray(T a[], long long n) {
  for (long long i = 0; i < n - 1; i++) cout << a[i] << " ";
  cout << a[n - 1] << endl;
}
const double EPS = 1e-9;
const long long INF = 0x7f7f7f7f;
long long dr8[8] = {1, -1, 0, 0, 1, -1, -1, 1};
long long dc8[8] = {0, 0, -1, 1, 1, 1, -1, -1};
long long dr4[4] = {0, 0, 1, -1};
long long dc4[4] = {-1, 1, 0, 0};
long long kn8r[8] = {1, 2, 2, 1, -1, -2, -2, -1};
long long kn8c[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int main() {
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long temp;
    cin >> temp;
    if (i == 1)
      ans += temp;
    else
      ans += (i * (temp - 1)) + 1;
  }
  cout << ans << "\n";
}
