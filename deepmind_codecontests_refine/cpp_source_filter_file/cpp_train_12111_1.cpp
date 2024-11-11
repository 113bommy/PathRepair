#include <bits/stdc++.h>
using namespace std;
template <class T>
T power(T N, T P) {
  return (P == 0) ? 1 : N * power(N, P - 1);
}
template <class T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int xx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int yy[] = {2, 2, 1, -1, -2, -2, -1, 1};
long long arr[100000 + 10 + 5], arr2[100000 + 10 + 5];
map<long long, long long> mp;
int main() {
  long long n, k, cnt;
  int i, a, b, g;
  double c, d, e, f;
  while (cin >> n >> k) {
    mp.clear();
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    for (i = 0; i < n; i++) {
      mp[arr[i]]++;
      arr2[i] = mp[arr[i]];
    }
    c = (double)n;
    d = (double)k;
    a = ceil(d / c);
    cnt = mp[arr[a - 1]];
    if (cnt > 1) {
      b = k - ((a - arr2[a - 1]) * n);
      e = (double)b;
      f = (double)cnt;
      g = ceil(e / f);
      cout << arr[a - 1] << " " << arr[g - 1] << endl;
    } else {
      b = k - ((a - 1) * n);
      cout << arr[a - 1] << " " << arr[b - 1] << endl;
    }
  }
  return 0;
}
