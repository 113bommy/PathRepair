#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
template <class T>
void printImpl(const vector<T>& coll) {
  copy(coll.begin(), coll.end(), ostream_iterator<T>(cout, " "));
  cout << endl;
}
template <class T, int N>
void printImpl(T (&coll)[N]) {
  copy(coll, coll + N, ostream_iterator<T>(cout, " "));
  cout << endl;
}
template <class Key, class Value>
void printImpl(const map<Key, Value>& data) {
  typename map<Key, Value>::const_iterator it;
  for (it = data.begin(); it != data.end(); ++it) {
    cout << it->first << ":" << it->second << endl;
  }
}
template <class T>
void printImpl(const T& data) {
  cout << data << endl;
}
long long a1, b1, a2, b2, L, R;
long long bd, k;
long long norm(long long x, long long M) {
  x = x % M;
  x = (x + M) % M;
  return x;
}
long long NOD(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return NOD(b, a % b);
}
long long extNOD(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long xx, yy;
  long long res = extNOD(b % a, a, xx, yy);
  x = yy - (b / a) * xx;
  y = xx;
  return res;
}
long long rev(long long a, long long M) {
  long long ddd = NOD(a, M);
  if (ddd != 1) {
    return rev(a / ddd, M / ddd);
  }
  long long x, y;
  long long d = extNOD(a, M, x, y);
  return x;
}
long long findK() {
  if (a1 == a2) return 0;
  long long A = a1 - a2;
  A = norm(A, b1);
  if (A % bd) return -1;
  long long b2_ = b2 / bd;
  long long b1_ = b1 / bd;
  long long x = A / bd * rev(b2_, b1_);
  x = norm(x, b1_);
  return x;
}
long long calc(long long M) {
  long long start = a2 + k * b2;
  if (start > M) return 0;
  long long d = b1 * b2 / bd;
  long long count = (M - start) / d + 1;
  return count;
}
int main() {
  cin >> b1 >> a1 >> b2 >> a2 >> L >> R;
  if (a1 > a2) {
    swap(a1, a2);
    swap(b1, b2);
  }
  bd = NOD(b1, b2);
  k = findK();
  if (k == -1) {
    cout << 0 << endl;
    return 0;
  }
  cout << calc(R) - calc(L - 1) << endl;
  return 0;
}
