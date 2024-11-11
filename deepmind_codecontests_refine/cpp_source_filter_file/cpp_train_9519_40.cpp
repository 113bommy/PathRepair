#include <bits/stdc++.h>
using namespace std;
long long cap;
struct record {
  long long a, b;
  record(long long a, long long b) {
    this->a = a;
    this->b = b;
  }
};
int main() {
  long long a, b, c, d, l;
  cin >> a >> b;
  cin >> c >> d;
  cap = c * d;
  cin >> l;
  if (cap == l) {
    cout << 0 << "\n";
    return 0;
  }
  cap = cap - l;
  long long total = 0;
  while (cap) {
    long long diff = min(c, cap);
    cap = cap - diff;
    total = total + min(a, diff * b);
  }
  cout << total << "\n";
}
