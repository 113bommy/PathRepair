#include <bits/stdc++.h>
using namespace std;
template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;
template <typename Args>
void kill(Args args) {
  cout << args << "\n";
  exit(0);
}
const double PI = acos(-1);
const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1010100;
int d1[N], d1r[N], d2[N], d2r[N];
long long a, b;
void solve(int testnum) {
  cin >> a >> b;
  long long n = a + b;
  int c1 = 0;
  for (long long i = 1; i * i <= a; i++) {
    if (a % i == 0) {
      d1[++c1] = i;
      d1r[c1] = i;
      if (i != a / i) {
        d1[++c1] = a / i;
        d1r[c1] = a / i;
      }
    }
  }
  int c2 = 0;
  for (long long i = 1; i * i <= b; i++) {
    if (b % i == 0) {
      d2[++c2] = i;
      d2r[c2] = i;
      if (i != b / i) {
        d2[++c2] = b / i;
        d2r[c2] = b / i;
      }
    }
  }
  sort(d1 + 1, d1 + c1 + 1);
  sort(d1r + 1, d1r + c1 + 1);
  sort(d2 + 1, d2 + c2 + 1);
  sort(d2r + 1, d2r + c2 + 1);
  reverse(d1r + 1, d1r + c1 + 1);
  reverse(d2r + 1, d2r + c2 + 1);
  long long minn = LLINF;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      long long x = i, y = n / i;
      int l = 1, r = c1;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (d1[mid] > x) {
          r = mid - 1;
        } else
          l = mid;
      }
      if (d1[l] <= x) {
        if (d1r[l] <= y) {
          minn = min(minn, 2ll * (x + y));
          continue;
        }
      }
      l = 1, r = c2;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (d2[mid] > x) {
          r = mid - 1;
        } else
          l = mid;
      }
      if (d2[l] <= x) {
        if (d2r[l] <= y) {
          minn = min(minn, 2ll * (x + y));
        }
      }
    }
  }
  cout << minn << "\n";
}
void precompute() {}
int main() {
  cout << fixed << setprecision(12);
  int testcase = 1;
  clock_t zzzx = clock();
  precompute();
  for (int i = 1; i <= testcase; i++) {
    solve(i);
  }
  double elapsed_time = (double)(clock() - zzzx) / CLOCKS_PER_SEC;
  cerr << "elapsed_time"
       << " = " << (elapsed_time) << "\n";
  return 0;
}
