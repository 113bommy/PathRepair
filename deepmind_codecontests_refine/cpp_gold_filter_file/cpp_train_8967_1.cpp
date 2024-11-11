#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e6 + 3;
inline long long add(long long a, long long b) {
  return (a % mod + b % mod) % mod;
}
inline long long sub(long long a, long long b) {
  return (a % mod - b % mod + mod) % mod;
}
inline long long mul(long long a, long long b) {
  return (a % mod * b % mod) % mod;
}
inline long long modexpo(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res % mod * a % mod) % mod;
    a = (a % mod * a % mod) % mod;
    b >>= 1;
  }
  return res;
}
inline long long modinv_Fermat(long long a) { return modexpo(a, mod - 2); }
inline long long divide(long long a, long long b) {
  return (a % mod * modexpo(b, mod - 2) % mod) % mod;
}
long long a[20][20];
long long b[20];
long long Ans[20];
struct Gauss {
  long long interactor(long long x) {
    long long f[11] = {(long long)1e6 + 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    long long curr = 1;
    long long ans = 0;
    for (long long i = 0; i <= 10; i++) {
      ans = add(ans, mul(f[i], curr));
      curr = mul(curr, x);
    }
    return ans;
  }
  void swap_row(long long i, long long j) {
    for (long long k = 0; k <= 10; k++) {
      swap(a[i][k], a[j][k]);
    }
    swap(b[i], b[j]);
  }
  void print_mat() {
    for (long long i = 0; i <= 10; i++) {
      for (long long j = 0; j <= 10; j++) {
        cout << fixed << setfill(' ') << setw(10);
        cout << a[i][j] << ' ';
      }
      cout << " : " << b[i];
      cout << '\n';
    }
  }
  void getans() {
    for (long long i = 0; i <= 10; i++) {
      cout << Ans[i] << ' ';
    }
    cout << '\n';
  }
  void forward_elimination() {
    for (long long i = 0; i <= 10; i++) {
      long long row, val;
      row = i;
      val = a[row][i];
      for (long long j = i + 1; j <= 10; j++) {
        if (a[j][i] > val) {
          val = a[j][i];
          row = j;
        }
      }
      if (row != i) swap_row(row, i);
      for (long long j = i + 1; j <= 10; j++) {
        long long d = divide(a[j][i], a[i][i]);
        for (long long k = i; k <= 10; k++) {
          a[j][k] = sub(a[j][k], mul(d, a[i][k]));
        }
        b[j] = sub(b[j], mul(d, b[i]));
      }
    }
  }
  void backward_substitution() {
    for (long long i = 10; i >= 0; i--) {
      Ans[i] = b[i];
      for (long long j = i + 1; j <= 10; j++) {
        Ans[i] = sub(Ans[i], mul(a[i][j], Ans[j]));
      }
      Ans[i] = divide(Ans[i], a[i][i]);
    }
  }
};
inline long long solve(long long x) {
  long long ans = 0;
  long long curr = 1;
  for (long long i = 0; i <= 10; i++) {
    ans = add(ans, mul(Ans[i], curr));
    curr = mul(curr, x);
  }
  return ans;
}
int main() {
  Gauss g;
  for (long long i = 0; i <= 10; i++) {
    cout << "? " << i << '\n';
    cout.flush();
    long long curr = 1;
    for (long long j = 0; j <= 10; j++) {
      a[i][j] = curr;
      curr = mul(curr, i);
    }
    cin >> b[i];
    if (b[i] == -1) {
      return 0;
    }
  }
  g.forward_elimination();
  g.backward_substitution();
  long long l = 0;
  long long r = 1e6 + 2;
  for (long long i = l; i <= r; i++) {
    long long h = solve(i);
    if (h == 0) {
      cout << "! " << i << '\n';
      cout.flush();
      return 0;
    }
  }
  cout << "! -1\n";
}
