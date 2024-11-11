#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
const long double EPS = 1e-9;
const int MOD = 1000000007;
const long long LLINF = 1000000000000000001;
const int maxn = 200000;
long long n, t;
long long a[maxn];
long long x[maxn];
long long b[maxn];
bool isStop[maxn];
void bad() {
  cout << "No\n";
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> t;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> x[i];
  b[n] = 3000000000000000000;
  for (int i = 1; i <= n; i++)
    if (x[i] < i) bad();
  for (int i = 2; i <= n; i++)
    if (x[i] < x[i - 1]) bad();
  long long pre = 0;
  for (int i = 1; i <= n; i++) {
    if (i < pre && x[i] != pre - 1) bad();
    if (i == pre || i == 1) {
      isStop[i] = true;
      pre = x[i] + 1;
    }
  }
  for (int i = 2; i <= n; i++) {
    if (isStop[i])
      b[i - 1] = a[i] + t - 1;
    else
      b[i - 1] = a[i] + t;
  }
  for (int i = 2; i <= n; i++)
    if (b[i] == b[i - 1]) bad();
  cout << "Yes\n";
  for (int i = 1; i <= n; i++) cout << b[i] << ' ';
  cout << '\n';
}
