#include <bits/stdc++.h>
clock_t t_;
using namespace std;
template <class T>
void print(T s) {
  cout << s << "\n";
}
template <class T>
void emax(T &a, T b) {
  a = (a < b ? b : a);
};
template <class T>
void emin(T &a, T b) {
  a = (a > b ? b : a);
}
template <class T>
void printC(T s) {
  for (auto &x : s) {
    cout << x << " ";
  }
  cout << "\n";
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(int argc, const char *argv[]) {
  t_ = clock();
  int n;
  cin >> n;
  vector<int> a(n + 1);
  a[0] = 0;
  for (int i = 0; i < int(n); i++) {
    cin >> a[i + 1];
  }
  n = (int)(a).size();
  long long ans = 0;
  long long l, r;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] < a[i]) {
      l = a[i] - a[i - 1];
      r = n - a[i];
    } else if (a[i - 1] >= a[i]) {
      l = a[i];
      r = a[i - 1] - a[i];
    }
    ans += (r * l);
  }
  print(ans);
  t_ = clock() - t_;
  cerr << setprecision(9) << fixed << ((float)t_ / CLOCKS_PER_SEC) << endl;
  return 0;
}
