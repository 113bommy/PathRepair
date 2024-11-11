#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  long long l = v.size();
  for (long long i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
const int N = 5000;
int t[N], n, T;
long double p[N];
vector<long double> A(N), B(N);
int32_t main() {
  scanf("%d %d", &n, &T);
  for (int i = 1; i <= n; i++) {
    scanf("%Lf %d", &p[i], &t[i]);
    p[i] /= 100.00;
  }
  long double ans = 0.0;
  A[0] = 1.0;
  for (int i = 1; i <= n; i++) {
    long double full = 1.0;
    for (int j = 1; j <= t[i]; j++) {
      full = (full * (1.0 - p[i]));
    }
    long double temp = 0;
    for (int j = 1; j <= T; j++) {
      temp = temp + A[j - 1];
      if (j > t[i]) {
        temp = temp - A[j - t[i] - 1] * full;
      }
      B[j] = temp * p[i];
      if (j >= t[i]) {
        B[j] += A[j - t[i]] * full;
      }
      ans += B[j];
      temp = temp * (1.0 - p[i]);
    }
    swap(A, B);
    B.clear();
    B.resize(N);
  }
  printf("%0.12Lf\n", ans);
  return 0;
}
