#include <bits/stdc++.h>
using namespace std;
long long Ar[200003];
long long CHK;
unsigned long long int mod(unsigned long long int n, unsigned long long int p) {
  unsigned long long int i, j, k, l;
  if (n >= p) return 0;
  unsigned long long int result = 1;
  for (i = 1; i <= n; i++) result = (result * i) % p;
  return result;
}
unsigned long long int powmod(unsigned long long int x,
                              unsigned long long int y,
                              unsigned long long int p) {
  unsigned long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void fun(long long left, long long right) {
  long long j, k, l;
  if (left > right) return;
  if ((left + right) % 2 == 0)
    k = (left + right) / 2;
  else
    k = (left + right - 1) / 2;
  Ar[k] = ++CHK;
  fun(left, k - 1);
  fun(k + 1, right);
}
int main() {
  long long T;
  T = 1;
  while (T--) {
    long long int N, i, j, M, A = 0, K, L, C = 0, D = 0, k = 1, a, b, c, l = 1,
                              m1, last, Z = 99, m2, z, sum = 0, sum3 = 0,
                              sum1 = 0, sum2 = 0, x, y, X, Y, ind;
    map<string, long long> mp;
    string s1;
    string s2;
    string s3 = "";
    stack<long long> st;
    priority_queue<
        pair<pair<long long, long long>, pair<long long, long long> > >
        Q;
    cin >> s1;
    m1 = 0;
    long long Arr[150] = {0};
    for (i = 0; i < s1.size(); i++) Arr[(int)s1[i]]++;
    m2 = 0;
    for (i = 1; i < 150; i++) {
      if (Arr[i] > 0) m1++;
      if (Arr[i] == 1) m2++;
    }
    if (m1 > 4 || m1 == 3 && m2 > 2 || m1 == 2 && m2 > 0 || m1 < 2) {
      cout << "No" << endl;
      continue;
    } else
      cout << "Yes" << endl;
  }
}
