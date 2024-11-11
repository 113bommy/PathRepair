#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000,100000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-10;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
long long a[100005];
long long b[100005];
long long num[100005];
bool cmp(long long x, long long y) { return a[x] < a[y]; }
int main(void) {
  long long n;
  cin >> n;
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    int x;
    scanf("%d", &x);
    a[i] = x;
    num[i] = i;
  }
  sort(num, num + n, cmp);
  long long div = (n) / 3;
  for (long long i = 0; i < div; i++) b[num[i]] = a[num[i]] - i;
  for (long long i = div; i < min(n, div + div); i++) b[num[i]] = i;
  for (long long i = div + div; i < n; i++) b[num[i]] = n - i - 1;
  cout << "YES" << endl;
  for (long long(i) = 0; (i) < (long long)(n); (i)++) cout << b[i] << " ";
  cout << endl;
  for (long long(i) = 0; (i) < (long long)(n); (i)++)
    cout << a[i] - b[i] << " ";
  cout << endl;
  return 0;
}
