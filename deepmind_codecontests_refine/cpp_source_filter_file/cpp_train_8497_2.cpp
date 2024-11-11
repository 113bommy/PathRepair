#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 1;
const long long MOD = 1e9 + 7;
const long long PHI = 1e9 + 6;
const long double eps = 1e-9;
const long double pi = atan(1) * 4;
void fileio() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
int n, a[100001];
bool flag = true;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n + 1; i++) {
    cin >> a[i];
    if (a[i] != 1 && a[i - 1] != 1) flag = false;
  }
  if (flag)
    cout << "perfect";
  else {
    cout << "ambiguous" << '\n';
    int k = 0;
    cout << 0 << " ";
    for (int i = 2; i <= n + 1; i++) {
      k += a[i - 1];
      for (int j = 1; j <= a[i]; j++) cout << k << " ";
    }
    cout << '\n';
    int l = 1, r = 1;
    cout << 0 << " ";
    for (int i = 2; i <= n + 1; i++) {
      for (int j = 1; j <= a[i] - 1; j++) cout << l << " ";
      cout << r << " ";
      l = r + 1;
      r += a[i];
    }
  }
  return 0;
}
