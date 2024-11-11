#include <bits/stdc++.h>
using i8 = char;
using u8 = unsigned char;
using i16 = short int;
using u16 = unsigned short int;
using i32 = long int;
using u32 = unsigned long int;
using i64 = long long int;
using u64 = unsigned long long int;
using f32 = float;
using f64 = double;
using f80 = long double;
using namespace std;
i32 p[1000010];
i32 d[1000010];
i32 n;
i32 m;
i32 a[300010];
u64 s[600020];
u64 x[600020];
void make_p(i32 n) {
  for (i32 i = 2; i <= n; i += 2) p[i] = 2;
  for (i32 i = 3; i <= n; i += 2) {
    if (p[i] == 0) {
      p[i] = i;
      for (i64 j = i; (j * (i64)i) <= (i64)n; ++j) {
        if (p[j * i] == 0) {
          p[j * i] = i;
        }
      }
    }
  }
}
void make_d(i32 n) {
  d[1] = 1;
  for (i32 i = 2; i <= n; ++i) {
    map<i32, i32> f;
    for (i32 j = i; j > 1; j /= p[j]) {
      f[p[j]]++;
    }
    d[i] = 1;
    for (auto it = f.begin(); it != f.end(); ++it) {
      d[i] *= (it->second + 1);
    }
  }
}
void make_s(i32 i, i32 l, i32 r) {
  if (l == r) {
    s[i] = a[l];
    x[i] = a[l];
    return;
  }
  i32 m = (l + r) / 2;
  make_s(i * 2, l, m);
  make_s(i * 2 + 1, m + 1, r);
  s[i] = s[i * 2] + s[i * 2 + 1];
  x[i] = x[i * 2] > x[i * 2 + 1] ? x[i * 2] : x[i * 2 + 1];
}
void rebuild_s(i32 i, i32 l, i32 r, i32 ll, i32 rr) {
  if (ll > r || rr < l || x[i] <= 2) return;
  if (l == r) {
    a[l] = d[a[l]];
    s[i] = a[l];
    x[i] = a[l];
    return;
  }
  i32 m = (l + r) / 2;
  rebuild_s(i * 2, l, m, ll, rr);
  rebuild_s(i * 2 + 1, m + 1, r, ll, rr);
  s[i] = s[i * 2] + s[i * 2 + 1];
  x[i] = x[i * 2] > x[i * 2 + 1] ? x[i * 2] : x[i * 2 + 1];
}
u64 sum_s(i32 i, i32 l, i32 r, i32 ll, i32 rr) {
  if (ll > r || rr < l) return 0;
  if (l == r) return s[i];
  if (l >= ll && r <= rr) return s[i];
  i32 m = (l + r) / 2;
  return sum_s(i * 2, l, m, ll, rr) + sum_s(i * 2 + 1, m + 1, r, ll, rr);
}
int main(void) {
  for (i32 i = 1; i <= 1000000; ++i) {
    for (i32 j = i; j <= 1000000; j += i) {
      ++d[j];
    }
  }
  scanf("%ld %ld", &n, &m);
  for (i32 i = 1; i <= n; ++i) scanf("%ld", &a[i]);
  make_s(1, 1, n);
  for (i32 i = 1; i <= m; ++i) {
    i32 t1, t2, t3;
    scanf("%ld %ld %ld", &t1, &t2, &t3);
    if (t1 == 1) {
      rebuild_s(1, 1, n, t2, t3);
    } else if (t1 == 2) {
      cout << sum_s(1, 1, n, t2, t3) << "\n";
    }
  }
  return 0;
}
