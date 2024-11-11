#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
const int INF = 1e9 + 9;
int n;
int a[26];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int g = 0, o = 0;
  for (int i = int(0); i <= int(n - 1); ++i) {
    cin >> a[i];
    g = gcd(g, a[i]);
    o += (a[i] % 2);
  }
  if (n == 1) {
    cout << a[0] << "\n";
    for (int i = int(1); i <= int(a[0]); ++i) cout << 'a';
    cout << "\n";
    return 0;
  }
  if (o > 1) {
    cout << "0";
    for (int i = int(0); i <= int(n - 1); ++i)
      for (int j = int(1); j <= int(a[i]); ++j) cout << char('a' + i);
    cout << "\n";
    return 0;
  }
  if (o == 1) {
    cout << g << "";
    char c = 0;
    for (int i = int(0); i <= int(n - 1); ++i) {
      if (a[i] % 2 == 1) c = i;
      a[i] /= g;
    }
    for (int i = int(1); i <= int(g); ++i) {
      for (int j = int(0); j <= int(n - 1); ++j)
        for (int k = int(1); k <= int(a[j] / 2); ++k) cout << char('a' + j);
      cout << char('a' + c);
      for (int j = int(n - 1); j >= int(0); --j)
        for (int k = int(1); k <= int(a[j] / 2); ++k) cout << char('a' + j);
    }
    cout << "\n";
    return 0;
  }
  cout << g << "";
  for (int i = int(1); i <= int(g); ++i) {
    if (i % 2 == 1)
      for (int j = int(0); j <= int(n - 1); ++j)
        for (int k = int(1); k <= int(a[j] / g); ++k) cout << char('a' + j);
    else
      for (int j = int(n - 1); j >= int(0); --j)
        for (int k = int(1); k <= int(a[j] / g); ++k) cout << char('a' + j);
  }
  cout << "\n";
  return 0;
}
