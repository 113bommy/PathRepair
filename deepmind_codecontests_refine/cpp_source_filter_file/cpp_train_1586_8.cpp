#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long int N = 100005;
bool arraySortedOrNot(long long int arr[], long long int n) {
  if (n == 0 || n == 1) return true;
  for (long long int i = 1; i < n; i++)
    if (arr[i - 1] > arr[i]) return false;
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    long long int a[n];
    long long int p[m];
    for (long long int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (long long int i = 0; i < m; ++i) {
      cin >> p[i];
    }
    sort(p, p + m);
    j = p[0];
    k = p[0];
    for (long long int i = 0; i < m; ++i) {
      if (j == -1) {
        j = p[i];
        k = p[i];
      } else if (i + 1 < m && p[i] + 1 == p[i + 1]) {
        k = p[i + 1];
      } else {
        sort(a + j - 1, a + k + 1);
        j = -1;
        k = -1;
      }
    }
    if (j != -1) {
      sort(a + j - 1, a + k + 1);
      j = -1;
      k = -1;
    }
    if (arraySortedOrNot(a, n))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
