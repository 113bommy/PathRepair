#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2, typename T3>
class triple {
 public:
  T1 first;
  T2 second;
  T3 third;
  triple() {
    first = 0;
    second = 0;
    third = 0;
  }
};
const long long maxn = 1e5 + 10;
const long long INF = 2e18;
long long n, a[maxn], b[maxn], m, k, temp1;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int((i)) = (0); ((i)) < ((n)); ((i))++) cin >> a[i];
  for (int((i)) = (0); ((i)) < ((m)); ((i))++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  a[n] = INF;
  for (int((i)) = (0); ((i)) < ((m)); ((i))++)
    if (a[temp1] <= b[i]) temp1++;
  if (temp1 == n)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
