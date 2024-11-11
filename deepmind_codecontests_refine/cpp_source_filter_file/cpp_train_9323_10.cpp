#include <bits/stdc++.h>
using namespace std;
void scanint(long long int &x);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, a, b, k;
  cin >> n >> a >> b >> k;
  long long int i = 0;
  string s;
  cin >> s;
  long long int pre = -1;
  long long int total = 0;
  for (i = 0; i < n; i++) {
    if (s[i] - '0') {
      total += (i - pre - 1) / 2;
      pre = i;
    }
  }
  total += (n - pre - 1) / 2;
  cout << total - a + 1 << endl;
  long long int m = 0;
  for (i = 0; i < n && total >= a; i++) {
    if (s[i] - '0' == 0) {
      m++;
      if (m == b) cout << i + 1 << " ", m = 0, total--;
    } else {
      m = 0;
    }
  }
  return 0;
}
void scanint(long long int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
