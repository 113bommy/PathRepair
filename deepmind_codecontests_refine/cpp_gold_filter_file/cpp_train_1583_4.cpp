#include <bits/stdc++.h>
using namespace std;
double eps = 1e-9;
const int INF = 1e9 + 7;
const int MAXN = int(3e5 + 7);
int n, p[2007];
string second;
pair<int, int> a[200];
void no() {
  puts("NO");
  exit(0);
}
int main() {
  cin >> second;
  n = second.size();
  for (int i = 0; i < n; i++)
    a[second[i] - 'a'].first++, a[second[i] - 'a'].second = second[i];
  sort(a, a + 26);
  reverse(a, a + 26);
  p[0] = 1;
  for (int i = 2; i <= n; i++) {
    bool ok = 1;
    for (int j = 2; j * 1ll * j <= i; j++)
      if (i % j == 0) ok = 0;
    if (ok) p[i] = 1;
  }
  for (int i = 2; i <= n; i++) {
    if (!p[i] || i <= n / 2) second[i - 1] = a[0].second, a[0].first--;
  }
  for (int i = n / 2 + 1; i <= n; i++) {
    if (p[i]) {
      for (int j = 0; j < 26; j++)
        if (a[j].first > 0) {
          second[i - 1] = a[j].second, a[j].first--;
          break;
        }
    }
  }
  if (a[0].first < 0) no();
  for (int j = 0; j < 26; j++)
    if (a[j].first > 0) second[0] = a[j].second, a[j].first--;
  cout << "YES\n" << second;
  return 0;
}
