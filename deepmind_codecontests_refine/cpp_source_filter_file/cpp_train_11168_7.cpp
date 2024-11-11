#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void pn(Arg1&& arg1) {
  cout << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void pn(Arg1&& arg1, Args&&... args) {
  cout << arg1 << "\n";
  pn(args...);
}
template <typename Arg1>
void ps(Arg1&& arg1) {
  cout << arg1 << " ";
}
template <typename Arg1, typename... Args>
void ps(Arg1&& arg1, Args&&... args) {
  cout << arg1 << " ";
  ps(args...);
}
template <typename Arg1>
void rn(Arg1&& arg1) {
  cin >> arg1;
}
template <typename Arg1, typename... Args>
void rn(Arg1&& arg1, Args&&... args) {
  cin >> arg1;
  rn(args...);
}
template <typename T>
inline T GCD(T a, T b) {
  while (b != 0) swap(b, a %= b);
  return a;
}
template <typename T>
T binpow(T a, T b) {
  T res = (T)1;
  if (b == (T)0) {
    return (T)1;
  }
  while (b > (T)0) {
    if (b & (T)1) {
      res *= a;
    }
    a *= a;
    b /= (T)2;
  }
  return res;
}
int main() {
  clock_t z = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[n + 1];
  long long sum = 0, total = 0;
  cout << "? 1 " << n << endl;
  cin >> total;
  long long presum = 0;
  for (int i = 2; i < n; i++) {
    cout << "? " << i << " " << n << endl;
    long long k;
    cin >> k;
    a[i - 1] = total - k - sum;
    sum += a[i - 1];
    if (i != n - 1) presum += sum;
  }
  cout << "? 1 " << n - 1 << endl;
  long long k;
  cin >> k;
  a[n] = total - k;
  a[n - 1] = total - presum - a[n];
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  fprintf(stderr, "Total Time elapsed: %.7f\n",
          (double)(clock() - z) / CLOCKS_PER_SEC),
      fflush(stderr);
  return 0;
}
