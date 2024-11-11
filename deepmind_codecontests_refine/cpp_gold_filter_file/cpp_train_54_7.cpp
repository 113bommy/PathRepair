#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> hash1, hash2;
int gcd(int x, int y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
int rev(int x) {
  int sum = 0;
  while (x) {
    sum *= 10;
    sum += x % 10;
    x /= 10;
  }
  return sum;
}
int main() {
  int x, y, w;
  cin >> x >> y >> w;
  for (int i = 1; i <= x; ++i) {
    int re = rev(i);
    int t = gcd(i, re);
    ++hash1[make_pair(i / t, re / t)];
  }
  int j = 0;
  long long bestx = x, besty = y, e = 0;
  long long sum = 0;
  for (; x;) {
    while (j < y && sum < w) {
      int l = rev(++j), jj;
      jj = gcd(j, l);
      pair<int, int> tmp = make_pair(l / jj, j / jj);
      sum += hash1[tmp];
      ++hash2[tmp];
    }
    if (sum >= w) {
      if (besty * bestx >= (long long)j * x) {
        bestx = x;
        besty = j;
        e = 1;
      }
    }
    int re = rev(x);
    int st = gcd(re, x);
    pair<int, int> tmp = make_pair(x / st, re / st);
    sum -= hash2[tmp];
    --hash1[tmp];
    --x;
  }
  if (e)
    cout << bestx << ' ' << besty << endl;
  else
    puts("-1");
  return 0;
}
