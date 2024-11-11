#include <bits/stdc++.h>
using namespace std;
string st;
int nb, ns, nc, pb, ps, pc, b = 0, s = 0, c = 0;
long long r;
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long cost(long long x) {
  return max(0, x * b - nb) * pb + max(0, x * s - ns) * ps +
         max(0, x * c - nc) * pc;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> st >> nb >> ns >> nc >> pb >> ps >> pc >> r;
  for (int i = 0; i < st.size(); i++) {
    if (st[i] == 'B')
      b++;
    else if (st[i] == 'S')
      s++;
    else
      c++;
  }
  long long left = 0, right = 1e13;
  while (left < right) {
    long long mid = left + (right - left + 1) / 2;
    long long c = cost(mid);
    if (c > r)
      right = mid - 1;
    else
      left = mid;
  }
  cout << left;
  return 0;
}
