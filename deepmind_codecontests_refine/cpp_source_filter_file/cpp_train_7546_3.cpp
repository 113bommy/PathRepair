#include <bits/stdc++.h>
int dr[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dc[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dr1[] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
int dc1[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int dr2[] = {0, 0, 1, -1};
int dc2[] = {1, -1, 0, 0};
using namespace std;
long long int n, fr[100006];
long long int bigmod(long long int n, long long int p) {
  if (p == 0) return 1;
  long long int x = bigmod(n, p / 2);
  x = (x * x) % 1000000007;
  if (p % 2 == 1) x = (x * n) % 1000000007;
  return x;
}
int main() {
  long long int i, j;
  fr[0] = 1;
  for (i = 01; i < 100006; i++) fr[i] = (fr[i - 1] * i) % 1000000007;
  while (cin >> n) {
    long long int p = fr[n * 2 - 1];
    long long int p1 = (fr[n] * fr[n * 2 - 1 - n]) % 1000000007;
    p1 = bigmod(p1, 1000000007 - 2);
    p = 2 * (p * p1) % 1000000007;
    p %= 1000000007;
    p = (p - n + 1000000007) % 1000000007;
    cout << p << endl;
  }
  return 0;
}
