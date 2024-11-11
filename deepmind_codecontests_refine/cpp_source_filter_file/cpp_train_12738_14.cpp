#include <bits/stdc++.h>
long long gcd(long long a, long long b) {
  if (a == 0 || b == 0) return (a + b);
  if (a > b) return (gcd(a % b, b));
  return (gcd(a, b % a));
}
long long lcm(long long a, long long b) { return ((a * b / gcd(a, b))); }
int sqr(int x) { return (x * x); }
void out() {
  puts("NO");
  exit(0);
}
using namespace std;
int n;
int p[100008];
int main() {
  cin >> n;
  for (int i = (int)(1); i < (int)(n + 1); ++i) p[i] = i;
  if (n == 1) {
    cout << "-1\n";
    return 0;
  }
  for (int i = (int)(1); i < (int)(n + 1); ++i) {
    swap(p[i], p[i + 1]);
    i++;
  }
  for (int i = (int)(n); i >= (int)(1); --i) cout << i << " ";
  cout << endl;
  return 0;
}
