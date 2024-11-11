#include <bits/stdc++.h>
using namespace std;
long long max(long long x, long long y) {
  if (x > y)
    return x;
  else
    return y;
}
long long min(long long x, long long y) {
  if (x < y)
    return x;
  else
    return y;
}
long long pow(long long Base, long long Power) {
  long long S = 1;
  for (long long i = 1; i <= Power; i++) S = S * Base;
  return S;
}
long long ar[100005];
vector<long long> V;
long long visited[100002];
long long level[100002];
int fx4[] = {1, -1, 0, 0};
int fy4[] = {0, 0, 1, -1};
long long tr(long long a, long long b, long long c) {
  if (a + b > c && a + c > b && b + c > a)
    return 1;
  else
    return 0;
}
long long seg(long long a, long long b, long long c) {
  if (a == b + c || b == a + c || c == a + b)
    return 1;
  else
    return 0;
}
int main() {
  long long ck = 0, n, m, d, a, b, c = 0, s = 0;
  cin >> a >> b >> c >> d;
  ck = tr(a, b, c);
  if (ck == 1) {
    cout << "TRIANGLE";
    return 0;
  }
  ck = tr(b, c, d);
  if (ck == 1) {
    cout << "TRIANGLE";
    return 0;
  }
  ck = tr(a, b, d);
  if (ck == 1) {
    cout << "TRIANGLE";
    return 0;
  }
  ck = tr(a, d, c);
  if (ck == 1) {
    cout << "TRIANGLE";
    return 0;
  }
  ck = 0;
  ck = seg(a, b, c);
  if (ck == 1) {
    cout << "SEGMENT";
    return 0;
  }
  ck = seg(b, c, d);
  if (ck == 1) {
    cout << "SEGMENT";
    return 0;
  }
  ck = seg(a, b, d);
  if (ck == 1) {
    cout << "SEGMENT";
    return 0;
  }
  ck = seg(a, d, c);
  if (ck == 1) {
    cout << "SEGMENT";
    return 0;
  } else
    cout << "IMPOSSIBLE";
  return 0;
}
