#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
long long A[N], B[N];
int n;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  long long a, b;
  cin >> a >> b;
  long long nww = a * b / (gcd(a, b));
  int inda = 0, indb = 0;
  A[inda++] = 0;
  B[indb++] = 0;
  long long c = a, d = b;
  while (c <= nww) {
    A[inda++] = c;
    c += a;
  }
  while (d <= nww) {
    B[indb++] = d;
    d += b;
  }
  int i = 0, j = 0;
  long long s1 = 0, s2 = 0;
  while (i < inda || j < indb) {
    if (A[i] == B[j]) {
      if (A[i] == nww) break;
      if (a > b)
        s1 += (min(A[i + 1], B[j + 1]) - A[i]);
      else
        s2 += (min(A[i + 1], B[j + 1]) - A[i]);
      i++;
      j++;
    } else if (A[i] < B[j]) {
      s1 += min(A[i + 1], B[j]) - A[i];
      i++;
    } else {
      s2 += min(A[i], B[j + 1]) - B[j];
      j++;
    }
  }
  if (s1 == s2)
    printf("Equal\n");
  else if (s1 < s2)
    printf("Dasha\n");
  else
    printf("Masha\n");
}
