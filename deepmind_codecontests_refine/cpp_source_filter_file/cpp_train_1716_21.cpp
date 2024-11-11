#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) { return a > b; }
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
long long c, hr, hb, wr, wb;
long long do1(long long pp) {
  long long newW = pp * wb;
  long long ct2 = pp;
  if (newW <= c) {
    long long lef = c - newW;
    long long ct1 = lef / wr;
    long long v1 = ct1 * hr;
    long long v2 = pp * hb;
    return v1 + v2;
  } else
    return -1;
}
long long solve1() {
  long long ct1 = c / wr;
  long long v1 = ct1 * hr;
  long long lef = c - (ct1 * wr);
  long long ct2 = lef / wb;
  if (ct2 > 0) {
    long long v2 = ct2 * hb;
    long long ans = v1 + v2;
    for (long long j = 1; j <= 1000000; j++) {
      long long ff = do1(j);
      if (ans < ff) ans = ff;
    }
    if (ans == -1)
      return v1;
    else
      return ans;
  } else {
    long long f1 = do1(1);
    long long ans = f1;
    for (long long j = 1; j <= 1000000; j++) {
      long long ff = do1(j);
      if (ans < ff) ans = ff;
    }
    if (ans == -1)
      return v1;
    else
      return ans;
  }
}
long long do2(long long pp) {
  long long newW = pp * wr;
  long long ct2 = pp;
  if (newW <= c) {
    long long lef = c - newW;
    long long ct1 = lef / wb;
    long long v1 = ct1 * hb;
    long long v2 = pp * hr;
    return v1 + v2;
  } else
    return -1;
}
long long solve2() {
  long long ct1 = c / wb;
  long long v1 = ct1 * hb;
  long long lef = c - (ct1 * wb);
  long long ct2 = lef / wr;
  if (ct2 > 0) {
    long long v2 = ct2 * hr;
    long long ans = v1 + v2;
    for (long long j = 1; j <= 1000000; j++) {
      long long ff = do2(j);
      if (ans < ff) ans = ff;
    }
    if (ans == -1)
      return v1;
    else
      return ans;
  } else {
    long long f1 = do2(1);
    long long ans = f1;
    for (long long j = 1; j <= 1000000; j++) {
      long long ff = do2(j);
      if (ans < ff) ans = ff;
    }
    if (ans == -1)
      return v1;
    else
      return ans;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> c >> hr >> hb >> wr >> wb;
  long long t1 = solve1();
  long long t2 = solve2();
  if (t1 > t2)
    cout << t1 << endl;
  else
    cout << t2 << endl;
  return 0;
}
