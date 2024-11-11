#include <bits/stdc++.h>
using namespace std;
const int N = 100009;
const long long oo = 10000000ll;
const long long BASE1 = 199711371ll;
const long long BASE2 = 197331977ll;
long long sum1, sum2;
long long a[N];
int n;
long long k;
char s[10];
int main() {
  int cnt = 0;
  scanf("%d %I64d", &n, &k);
  for (int i = 0; i <= n; i++) {
    scanf("%s", s);
    if (s[0] == '?')
      a[i] = oo;
    else
      sscanf(s, "%I64d", &a[i]), ++cnt;
  }
  if (!k) {
    if (a[0] == oo)
      if (cnt & 1)
        cout << "Yes";
      else
        cout << "No";
    else
      cout << ((!a[0]) ? "Yes" : "No");
    return 0;
  }
  if (cnt <= n) {
    if ((n + 1) & 1)
      cout << "No";
    else
      cout << "Yes";
    return 0;
  }
  sum1 = 0;
  sum2 = 0;
  for (int i = n; i >= 0; i--) {
    sum1 = ((sum1 * k) % BASE1 + a[i]) % BASE1;
    sum2 = ((sum2 * k) % BASE2 + a[i]) % BASE2;
  }
  if (sum1 || sum2)
    cout << "No";
  else
    cout << "Yes";
}
