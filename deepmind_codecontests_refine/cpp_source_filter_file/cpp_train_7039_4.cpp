#include <bits/stdc++.h>
using namespace std;
long long get_ref(long long a) {
  long long ans;
  for (long long i = 1; i <= 1000000000; i *= 10) {
    if (a >= i)
      continue;
    else {
      ans = i / 2;
      break;
    }
  }
  return ans;
}
long long reflection(long long a) {
  int argham;
  long long ref;
  for (long long i = 1; i <= 1000000000; i *= 10) {
    if (a >= i)
      continue;
    else {
      ref = i - 1;
      break;
    }
  }
  return ((ref - a) * a);
}
int main() {
  long long i, t, m, n, j, k;
  long long l, r;
  long long maxx = 0;
  cin >> l >> r;
  long long refrence = get_ref(r);
  if (r < refrence)
    cout << reflection(r) << endl;
  else {
    if (l < refrence)
      cout << reflection(refrence) << endl;
    else
      cout << reflection(l) << endl;
  }
}
