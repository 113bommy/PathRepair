#include <bits/stdc++.h>
using namespace std;
long long n, sq, ia, ib, ic, ja, jb, jc;
long long Min = 1000000000000000000;
long long Max = 0;
void check(long long a, long long b, long long c) {
  vector<long long> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  sort(v.begin(), v.end());
  do {
    a = v[0] + 1;
    b = v[1] + 2;
    c = v[2] + 2;
    long long res = a * b * c - (v[0] * v[1] * v[2]);
    if (res < Min) {
      Min = res;
      ia = a;
      ib = b;
      ic = c;
    }
    if (res > Max) {
      Max = res;
      ja = a;
      jb = b;
      jc = c;
    }
  } while (next_permutation(v.begin(), v.end()));
}
int main() {
  long long a, b, c;
  cin >> n;
  long long sq = (long long)sqrt((double)n);
  for (a = 1; a <= sq; a++) {
    if (n % a == 0) {
      long long t = a;
      long long sqr = (long long)sqrt((double)t);
      for (int j = 1; j <= sqr; j++) {
        if (t % j == 0) {
          b = j;
          c = t / j;
          check(n / a, b, c);
        }
      }
      t = n / a;
      sqr = (long long)sqrt((double)t);
      for (int j = 1; j <= sqr; j++) {
        if (t % j == 0) {
          b = j;
          c = t / j;
          check(a, b, c);
        }
      }
    }
  }
  cout << Min << ' ' << Max << endl;
  return 0;
}
