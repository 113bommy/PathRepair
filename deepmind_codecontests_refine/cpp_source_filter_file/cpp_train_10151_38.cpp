#include <bits/stdc++.h>
using namespace std;
int compare(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
unsigned long long lcm(unsigned long long a, unsigned long long b) {
  unsigned long long umax = ULLONG_MAX;
  umax /= b;
  unsigned long long buf = a / gcd(a, b);
  if (umax > buf)
    return buf * b;
  else
    return 0;
}
int main() {
  unsigned long long t, w, b, answer = 0;
  cin >> t >> w >> b;
  unsigned long long _lcm = lcm(w, b);
  unsigned long long _min = min(w, b);
  if (_lcm != 0) {
    answer += (t / _lcm) * _min;
    --answer;
    answer += min((t % _lcm) + 1, _min);
  } else
    answer = min(w, b) - 1;
  unsigned long long xgcd = gcd(answer, t);
  answer /= xgcd;
  t /= xgcd;
  cout << answer << "/" << t;
}
