#include <bits/stdc++.h>
long long mod = 1e9 + 7;
template <typename T>
inline long long pwr(T base, T n) {
  long long ans = 1;
  while (n > 0) {
    if (n % 2 == 1) ans = ans * base;
    base = base * base;
    n /= 2;
  }
  return ans;
}
struct range {
  int l, h;
};
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  int a[10000] = {0};
  for (int i = 0; i < n; i++) cin >> a[i];
  int flag = 0;
  int sum = 0;
  int i = 0;
  while (a[i] != 0) {
    if (a[i] <= 8)
      sum += a[i];
    else {
      sum += 8;
      a[i + 1] += (a[i] - 8);
    }
    if (sum >= k) {
      flag = 1;
      break;
    }
    i++;
  }
  if (flag == 1)
    cout << i + 1 << "\n";
  else
    cout << "-1\n";
  return 0;
}
