#include <bits/stdc++.h>
using namespace std;
long long INF = 1e9 + 7;
int main() {
  long long l, r;
  cin >> l >> r;
  long long k1 = 0;
  long long k2 = 0;
  long long k;
  long long l1 = l;
  long long r1 = r;
  long long i;
  long long ost1[100], ost2[100];
  while (l1 / 2 != 0) {
    ost1[k1] = l1 % 2;
    l1 = l1 / 2;
    k1++;
  }
  ost1[k1] = l1;
  k1++;
  while (r1 / 2 != 0) {
    ost2[k2] = r1 % 2;
    r1 = r1 / 2;
    k2++;
  }
  ost2[k2] = r1;
  k2++;
  long long j;
  long long s = 1;
  k = max(k1, k2);
  for (i = k; i > 0; i++)
    if (ost1[i - 1] == ost2[i - 1])
      continue;
    else {
      for (j = 0; j < i; j++) s = s * 2;
      cout << s - 1;
      return 0;
    }
  cout << 0;
  return 0;
}
