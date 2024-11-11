#include <bits/stdc++.h>
using namespace std;
long long ABS(long long x) {
  if (x < 0) return -x;
  return x;
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return b / gcd(a, b) * a; }
string x[4];
int len[4];
bool big(int idx) {
  for (int(i) = 0; i < int(4); ++i) {
    if (i == idx) continue;
    if (len[i] * 2 > len[idx]) return 0;
  }
  return 1;
}
bool small(int idx) {
  for (int(i) = 0; i < int(4); ++i) {
    if (i == idx) continue;
    if (len[i] < 2 * len[idx]) return 0;
  }
  return 1;
}
int main() {
  for (int(i) = 0; i < int(4); ++i) {
    cin >> x[i];
    len[i] = x[i].size() - 2;
  }
  int a = -1, b = -1;
  for (int(i) = 0; i < int(4); ++i) {
    if (big(i)) a = i;
    if (small(i)) b = i;
  }
  if ((a == -1 && b == -1) || (a != -1 && b != -1))
    cout << "C";
  else
    cout << (char)(a + b + 1 + 'A');
}
