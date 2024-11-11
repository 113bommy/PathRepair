#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
T integer_partition_point(T l, T r, const function<bool(T)>& predicate) {
  while (r - l > 1) {
    T m = (l + r) / 2;
    if (predicate(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}
template <typename T>
T argminimal(const function<T(T)>& f, T l, T r) {
  while (r - l > 1) {
    T m = (l + r) / 2;
    if (f(m) - f(m - 1) < 0) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}
template <typename T>
T minimal(const function<T(T)>& f, T l, T r) {
  return f(argminimal<T>(f, l, r));
}
template <typename T>
T argmaximal(const function<T(T)>& f, T l, T r) {
  while (r - l > 1) {
    T m = (l + r) / 2;
    if (f(m) - f(m - 1) > 0) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}
template <typename T>
T maximal(const function<T(T)>& f, T l, T r) {
  return f(argmaximal<T>(f, l, r));
}
double argminimal(const function<double(double)>& f, double l, double r,
                  int iter = 80) {
  for (int i = 0; i < iter; ++i) {
    double c1 = (l * 2 + r) / 3, c2 = (l + r * 2) / 3;
    if (f(c1) > f(c2)) {
      l = c1;
    } else {
      r = c2;
    }
  }
  return l;
}
double minimal(const function<double(double)>& f, double l, double r,
               int iter = 80) {
  return f(argminimal(f, l, r, iter));
}
double argmaximal(const function<double(double)>& f, double l, double r,
                  int iter = 80) {
  for (int i = 0; i < iter; ++i) {
    double c1 = (l * 2 + r) / 3, c2 = (l + r * 2) / 3;
    if (f(c1) > f(c2)) {
      r = c2;
    } else {
      l = c1;
    }
  }
  return l;
}
double maximul(const function<double(double)>& f, double l, double r,
               int iter = 80) {
  return f(argmaximal(f, l, r, iter));
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  map<int, long long> hist;
  for (int i = 0; i < (int)(n); ++i) {
    scanf("%lld", &a[i]);
    ++hist[a[i]];
  }
  for (auto& p : hist) {
    if (p.second >= k) {
      cout << 0 << endl;
      return 0;
    }
  }
  const long long INF = 1e18;
  long long ans = 1e18;
  long long u =
      integer_partition_point<long long>(0, 1e9 + 1, [&](long long m) {
        int c = count_if((a).begin(), (a).end(), [&](int v) { return v >= m; });
        return c >= k;
      });
  chmin(ans, accumulate((a).begin(), (a).end(), k - hist[u],
                        [&](long long a, long long e) {
                          return a + max(e - (u + 1), 0LL);
                        }));
  long long d =
      integer_partition_point<long long>(0, 1e9 + 1, [&](long long m) {
        int c = count_if((a).begin(), (a).end(), [&](int v) { return v <= m; });
        return c < k;
      });
  ++d;
  chmin(ans, accumulate((a).begin(), (a).end(), k - hist[u],
                        [&](long long a, long long e) {
                          return a + max(d - 1 - e, 0LL);
                        }));
  auto sandCost = [&](long long m) -> long long {
    return accumulate((a).begin(), (a).end(), k - hist[m],
                      [&](long long a, long long e) {
                        a += max(e - (m + 1), 0LL);
                        a += max(m - 1 - e, 0LL);
                        return a;
                      });
  };
  chmin(ans, minimal<long long>(sandCost, 0, 1e9 + 1));
  cout << ans << endl;
  return 0;
}
