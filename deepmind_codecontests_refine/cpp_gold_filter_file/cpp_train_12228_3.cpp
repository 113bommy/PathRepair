#include <bits/stdc++.h>
using namespace std;
const int MAXS = 100000;
inline long long get(long long n, long long ma, long long b) {
  return max(ma, (6 * n + b - 1) / b) * b;
}
int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  if (a * b >= 6 * n) {
    cout << a * b << endl;
    cout << a << " " << b << endl;
  } else {
    long long best = b;
    for (int i = b; i <= MAXS; i++)
      if (get(n, a, best) > get(n, a, i)) best = i;
    long long best2 = a;
    for (int i = a; i <= MAXS; i++)
      if (get(n, b, best2) > get(n, b, i)) best2 = i;
    if (get(n, a, best) < get(n, b, best2)) {
      a = max(a, (6 * n + best - 1) / best);
      b = best;
    } else {
      a = best2;
      b = max(b, (6 * n + best2 - 1) / best2);
    }
    cout << a * b << endl;
    cout << a << " " << b << endl;
  }
}
