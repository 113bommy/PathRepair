#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, l;
  cin >> a >> b >> c >> l;
  long long max = 0;
  for (int i = 0; i <= l; i++) max += (l - i + 1) * (l - i + 2) / 2;
  if (a >= b + c + l || b >= a + c + l || c >= b + a + l) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i <= l; i++) {
    if (a + i < b + c) continue;
    long long cur = min((i + a - b - c), l - i);
    long long sub = ((cur + 2) * (cur + 1)) / 2;
    max -= sub;
  }
  for (int i = 0; i <= l; i++) {
    if (b + i < a + c) continue;
    long long cur = min((i + b - a - c), l - i);
    long long sub = ((cur + 2) * (cur + 1)) / 2;
    max -= sub;
  }
  for (int i = 0; i <= l; i++) {
    if (c + i < a + b) continue;
    long long cur = min((i + c - b - a), l - i);
    long long sub = ((cur + 2) * (cur + 1)) / 2;
    max -= sub;
  }
  cout << max << "\n";
  return 0;
}
