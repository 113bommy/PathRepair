#include <bits/stdc++.h>
using namespace std;
int n, i, a[26], x, maxi;
long long int ans = 1;
char s[100003];
int main() {
  cin >> n;
  cin >> s;
  for (i = 0; i < n; i++) a[s[i] - 'A']++;
  maxi = 0;
  if (a[0] > maxi) maxi = a[0];
  if (a[2] > maxi) maxi = a[2];
  if (a['G' - 'A'] > maxi) maxi = a['G' - 'A'];
  if (a['T' - 'A'] > maxi) maxi = a['T' - 'A'];
  if (a[0] == maxi) x++;
  if (a[2] == maxi) x++;
  if (maxi == a['G' - 'A']) x++;
  if (maxi == a['T' - 'A']) x++;
  while (n--) {
    ans *= x;
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}
