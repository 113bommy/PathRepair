#include <bits/stdc++.h>
long long mod = 1e9 + 7;
inline long long pwr(long long base, long long n) {
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
  int n, m;
  cin >> n >> m;
  int a[n], b[10] = {0};
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    int first;
    cin >> first;
    b[first] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (b[a[i]]) cout << a[i] << " ";
  }
  return 0;
}
