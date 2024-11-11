#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:128000000")
using namespace std;
const double PI = acos(-1.0);
template <class T>
T SQR(const T &a) {
  return a * a;
}
bool win(unsigned long long a, unsigned long long b) {
  if (a == 0 || b == 0) return false;
  if (a < b) swap(a, b);
  if (a % b == 0) return true;
  if (!win(b, a % b)) return true;
  a = (a - a % b) - 1;
  if (b & 1) return a % (2 * b) >= b;
  if (double(b) * b < 3e18) a %= b * (b + 1);
  if (double(b) * b < 3e18 || a < b * b) return a % (2 * b) >= b;
  return true;
}
void run() {
  int t;
  cin >> t;
  for (int i = (0), ei = (t); i < ei; i++) {
    unsigned long long a, b;
    cin >> a >> b;
    puts(win(a, b) ? "First" : "Second");
  }
}
int main() {
  time_t beg = clock();
  run();
  return 0;
}
