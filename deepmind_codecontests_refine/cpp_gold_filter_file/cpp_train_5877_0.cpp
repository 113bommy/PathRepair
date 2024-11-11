#include <bits/stdc++.h>
using namespace std;
template <class T>
int size(const T &x) {
  return x.size();
}
const int INF = ~(1 << 31);
const double EPS = 1e-9;
const double pi = acos(-1);
template <class T>
T smod(T a, T b) {
  return (a % b + b) % b;
}
long long x;
int n, d;
int *a, *b;
long long getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  for (int i = 0; i < n; i = i + 1) {
    a[i] = i + 1;
  }
  for (int i = 0; i < n; i = i + 1) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (int i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (int i = 0; i < n; i = i + 1) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
}
int main() {
  cin >> n >> d >> x;
  a = new int[n];
  b = new int[n];
  initAB();
  vector<int> from(n);
  for (__typeof(0) i = (0); i < (n); ++i) {
    from[a[i] - 1] = i;
  }
  vector<int> c(n, 0);
  int s = 30;
  vector<int> bs;
  for (__typeof(0) i = (0); i < (n); ++i) {
    if (b[i]) bs.push_back(i);
  }
  bs.push_back(INF);
  for (__typeof(0) i = (0); i < (n); ++i) {
    for (int j = n - 1; j >= max(n - s, 0); j--) {
      if (from[j] <= i && b[i - from[j]]) {
        c[i] = j + 1;
        break;
      }
    }
    if (c[i] == 0) {
      int j = 0;
      while (bs[j] <= i) {
        c[i] = max(c[i], a[i - bs[j]]);
        j++;
      }
    }
  }
  for (__typeof(0) i = (0); i < (n); ++i) {
    cout << c[i] << endl;
  }
  return 0;
}
