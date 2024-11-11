#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T BM(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T mdINV(T a, T M) {
  return BM(a, M - 2, M);
}
template <class T>
inline T PW(T p, T e) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
template <class T>
string NTS(T Number) {
  stringstream ss;
  ss << Number;
  return ss.str();
}
template <class T>
T stringtonumber(const string &Text) {
  istringstream ss(Text);
  T result;
  return ss >> result ? result : 0;
}
template <class T>
bool ISLEFT(T a, T b, T c) {
  if (((a.first.first - b.first.first) * (b.second.second - c.second.second) -
       (b.first.first - c.first.first) * (a.second.second - b.second.second)) <
      0.0)
    return 1;
  else
    return 0;
}
int n;
int a[200000 + 4];
double cum[200000 + 2];
double his(long long int mid, long long int ko) {
  double first = cum[n] - cum[n - ko];
  first += cum[mid] - cum[mid - 1 - ko];
  first = first / (double)(2 * (double)ko + 1);
  first -= (double)a[mid];
  return first;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  cum[0] = 0;
  for (long long int i = 1; i <= n; i++) {
    cum[i] = (cum[i - 1] + (double)a[i]);
  }
  double res = 0;
  int in = 1;
  int num = 0;
  for (int i = 1; i <= n; i++) {
    int x1 = min(i - 1, n - i);
    int lo = 1;
    int hi = x1;
    for (int j = 1; j <= 200; j++) {
      int first = (hi - lo) / 3;
      int mid = (lo + first);
      int mid1 = (hi - first);
      double val = his(i, mid);
      double val1 = his(i, mid1);
      if (mid < mid1)
        lo = mid;
      else
        hi = mid1;
    }
    lo = max(0, lo - 10);
    hi = min(x1, hi + 10);
    assert(hi - lo <= 100);
    for (int j = lo; j <= hi; j++) {
      double ho = his(i, j);
      if (ho > res) {
        res = ho;
        in = i;
        num = j;
      }
    }
  }
  int lo = in - num;
  int hi = in + num;
  cout << hi - lo + 1 << endl;
  int ar[hi - lo + 2];
  int sz1 = 0;
  for (int i = lo; i <= in; i++) {
    ar[++sz1] = a[i];
  }
  for (int j = n; j > n - num; j--) ar[++sz1] = a[j];
  for (int i = 1; i <= sz1; i++) {
    if (i == 1)
      printf("%d", ar[i]);
    else
      printf(" %d", ar[i]);
  }
  printf("\n");
  return 0;
}
