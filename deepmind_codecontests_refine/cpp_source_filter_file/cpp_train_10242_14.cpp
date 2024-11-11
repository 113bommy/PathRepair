#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long pow2(long long n) {
  long long x = 1;
  for (long long i = 1; i <= n; i++) {
    x *= 2;
  }
  return x;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long arr[3][3], l[3][3];
  memset(l, 0, sizeof(l));
  for (long long i = 0; i < 3; i++) {
    for (long long j = 0; j < 3; j++) {
      cin >> arr[i][j];
    }
  }
  for (long long i = 0; i < 3; i++) {
    for (long long j = 0; j < 3; j++) {
      if (arr[i][j] % 2 == 1) {
        if (i + 1 < 3) l[i + 1][j] = !l[i + 1][j];
        if (i - 1 >= 0) l[i - 1][j] = !l[i - 1][j];
        if (j + 1 < 3) l[i][j + 1] = !l[i][j + 1];
        if (j - 1 >= 0) l[i][j - 1] = !l[i][j - 1];
        l[i][j] = !l[i][j];
      }
    }
  }
  for (long long i = 0; i < 3; i++) {
    for (long long j = 0; j < 3; j++) cout << !l[i][j] << "\t";
    cout << endl;
  }
}
