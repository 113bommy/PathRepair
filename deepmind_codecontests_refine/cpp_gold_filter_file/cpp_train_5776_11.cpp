#include <bits/stdc++.h>
using namespace std;
int n;
long long d[500009];
string s;
double ans;
int main() {
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    d[i + 1] = d[i];
    if (s[i] == 'I' || s[i] == 'E' || s[i] == 'A' || s[i] == 'O' ||
        s[i] == 'U' || s[i] == 'Y')
      d[i + 1]++;
  }
  for (int i = 1; i <= n; i++) d[i] += d[i - 1];
  for (int i = 1; i <= n; i++) ans += (double)(d[n] - d[i - 1]) / i;
  for (int i = 1; i < n; i++) ans -= (double)(d[n - i]) / i;
  printf("%.6llf", ans);
}
