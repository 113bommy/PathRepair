#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
int arr[200005];
long long int cn = 1;
void dfs(int i, int j, int a, int b) {
  arr[i] = 1;
  cn++;
  if (i + a <= j && !arr[i + a]) dfs(i + a, j, a, b);
  if (i - b >= 0 && !arr[i - b]) dfs(i - b, j, a, b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int m, a, b;
  cin >> m >> a >> b;
  long long int g = gcd(a, b);
  if (a == 1) {
    cout << ((m * (m + 1) / 2) + m + 1) << endl;
    return 0;
  }
  if (m < a) {
    cout << (m + 1) << endl;
    return 0;
  }
  long long int ans = 0;
  long long int c;
  if (a + b - g <= m) {
    ans += (m - (a + b - g) + 1);
    for (c = a + b - g; c <= m; c++) {
      if (c % g == 0) break;
      ans += c / g;
    }
    long long int left = m - c + 1;
    long long int l = c + (left / g) * g - 1;
    for (int k = l + 1; k <= m; k++) {
      ans += k / g;
    }
    long long int lft = (l - c + 1) / g;
    long long int ms = 0;
    for (long long int j = 1; j < g; j++) {
      ms += j * lft;
    }
    ans += (((c + l) * (l - c + 1) / 2) - ms) / g;
  }
  for (int i = 0; i < a + b; i++) arr[i] = 0;
  arr[0] = 1;
  for (int i = 1; i < min(a + b - g, m + 1); i++) {
    if (i >= a) {
      if (arr[i - a]) {
        dfs(i, i, a, b);
      }
    }
    ans += cn;
  }
  cout << (ans + 1) << endl;
  return 0;
}
