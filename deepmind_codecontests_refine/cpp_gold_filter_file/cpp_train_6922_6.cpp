#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
const unsigned long long MOD = 1000000007;
const int NR_CIFRE = 100005;
int main() {
  long long n, m, k, l, v1[MAX], v2[MAX];
  cin >> n >> m >> k >> l;
  for (int i = 1; i <= n; i++) cin >> v1[i];
  for (int i = 1; i <= m; i++) cin >> v2[i];
  if (v1[k] < v2[m - l + 1])
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
