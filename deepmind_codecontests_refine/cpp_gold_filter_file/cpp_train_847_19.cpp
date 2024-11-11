#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const long long IINF = 1LL << 62;
const int maxn = 15000005;
int divr[maxn];
void divisor() {
  for (int i = 2; i < sqrt(maxn); i++) {
    if (!divr[i]) {
      for (int j = i * i; j < maxn; j += i)
        if (!divr[j]) divr[j] = i;
    }
  }
  for (int i = 1; i < maxn; i++)
    if (!divr[i]) divr[i] = i;
}
int main() {
  long long a, b, m;
  cin >> a >> b >> m;
  long long c = 1000000000;
  for (long long i = 0; i <= min(a, m); i++) {
    long long x = (i * c) % m;
    long long tmp = (m - x) % m;
    if (tmp > b) {
      cout << 1 << " ";
      string s = to_string(i);
      int x = 9 - (int)s.length();
      for (int j = 1; j <= x; j++) cout << 0;
      cout << s;
      return 0;
    }
  }
  cout << 2;
}
