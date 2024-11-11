#include <bits/stdc++.h>
using namespace std;
int tests;
long long a, b;
int win(long long a, long long b) {
  long long t;
  if (a > b) t = a, a = b, b = t;
  if (!a) return 0;
  if (!win(b % a, a)) return 1;
  if ((((b / a) * a) % (a + 1)) % 3)
    return 0;
  else
    return 1;
}
int main() {
  cin >> tests;
  for (int i = 1; i <= tests; i++) {
    cin >> a >> b;
    if (win(a, b))
      cout << "First" << endl;
    else
      cout << "Second" << endl;
  }
  return 0;
}
