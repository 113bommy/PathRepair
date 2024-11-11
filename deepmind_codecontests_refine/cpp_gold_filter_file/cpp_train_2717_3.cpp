#include <bits/stdc++.h>
using namespace std;
string s;
const int INF = 1e9;
bool pos, neg;
long long a, mn = INF, mx = -INF, n, sum;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &a);
    mn = min(a, mn);
    mx = max(a, mx);
    sum += abs(a);
  }
  if (n == 1) {
    cout << a;
    return 0;
  }
  if (mx < 0)
    cout << abs(sum) - abs(2 * mx);
  else if (mn > 0)
    cout << abs(sum) - 2 * mn;
  else
    cout << abs(sum);
}
