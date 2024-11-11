#include <bits/stdc++.h>
using namespace std;
string burger;
long long na, nb, nc;
long long pa, pb, pc;
long long r;
long long a, b, c;
bool check(long long mid) {
  long long rem = r;
  if (na < mid * a) {
    long long lage = (mid * a - na) * pa;
    if (lage > rem) return false;
    rem -= lage;
  }
  if (nb < mid * b) {
    long long lage = (mid * b - nb) * pb;
    if (lage > rem) return false;
    rem -= lage;
  }
  if (nc < mid * c) {
    long long lage = (mid * c - nc) * pc;
    if (lage > rem) return false;
  }
  return true;
}
int main() {
  cin >> burger >> na >> nb >> nc >> pa >> pb >> pc >> r;
  for (char ca : burger) {
    if (ca == 'B')
      a++;
    else if (ca == 'S')
      b++;
    else
      c++;
  }
  long long lo = 0;
  long long hi = 1000000000000;
  long long ans = 0;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    if (check(mid)) {
      ans = max(ans, mid);
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << ans;
}
