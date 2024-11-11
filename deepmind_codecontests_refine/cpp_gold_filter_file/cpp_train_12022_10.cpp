#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const double PI = acos(-1);
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename Ch, typename Tr, typename C, typename = decltype(begin(C()))>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, const C &c) {
  os << '[';
  for (auto i = begin(c); i != end(c); ++i)
    os << (i == begin(c) ? "" : " ") << *i;
  return os << ']';
}
template <class S, class T>
ostream &operator<<(ostream &o, const pair<S, T> &t) {
  return o << '(' << t.first << ',' << t.second << ')';
}
template <int N, class Tp>
void output(ostream &, const Tp &) {}
template <int N, class Tp, class, class... Ts>
void output(ostream &o, const Tp &t) {
  if (N) o << ',';
  o << get<N>(t);
  output<N + 1, Tp, Ts...>(o, t);
}
template <class... Ts>
ostream &operator<<(ostream &o, const tuple<Ts...> &t) {
  o << '(';
  output<0, tuple<Ts...>, Ts...>(o, t);
  return o << ')';
}
template <class T>
void output(T t, char z = 10) {
  if (t < 0) t = -t, putchar(45);
  int c[20];
  int k = 0;
  while (t) c[k++] = t % 10, t /= 10;
  for (k || (c[k++] = 0); k;) putchar(c[--k] ^ 48);
  putchar(z);
}
template <class T>
void outputs(T t) {
  output(t);
}
template <class S, class... T>
void outputs(S a, T... t) {
  output(a, 32);
  outputs(t...);
}
template <class T>
void output(T *a, int n) {
  for (int i = 0; i < (int)(n); ++i) cout << a[i] << (i != n - 1 ? ',' : '\n');
}
template <class T>
void output(T *a, int n, int m) {
  for (int i = 0; i < (int)(n); ++i) output(a[i], m);
}
template <class T>
bool input(T &t) {
  int n = 1, c;
  for (t = 0; !isdigit(c = getchar()) && ~c && c - 45;)
    ;
  if (!~c) return 0;
  for (c - 45 && (n = 0, t = c ^ 48); isdigit(c = getchar());)
    t = 10 * t + c - 48;
  t = n ? -t : t;
  return 1;
}
template <class S, class... T>
bool input(S &a, T &...t) {
  input(a);
  return input(t...);
}
template <class T>
bool inputs(T *a, int n) {
  for (int i = 0; i < (int)(n); ++i)
    if (!input(a[i])) return 0;
  return 1;
}
long long pown[20];
int get(long long S, int i) { return S / pown[i] % pown[1]; }
long long change(long long S, int i, int x) {
  S -= get(S, i) * pown[i];
  S += x * pown[i];
  return S;
}
void init(int n, int m) {
  pown[0] = 1;
  for (int i = 0; i < (int)(m); ++i) pown[i + 1] = pown[i] * n;
}
int L[5], R[5];
double W[5];
int ok[10000];
int main() {
  init(3, 6);
  int n;
  while (input(n)) {
    for (int i = 0; i < (int)(n); ++i) {
      input(L[i], R[i]);
      W[i] = R[i] - L[i] + 1;
    }
    for (int S = 0; S < (int)(pown[n]); ++S) {
      vector<int> v;
      for (int i = 0; i < (int)(n); ++i) {
        v.push_back(get(S, i));
      }
      sort((v).begin(), (v).end());
      ok[S] = (v[1] == 1);
    }
    double ans = 0;
    for (int val = 1; val <= 10000; ++val) {
      for (int S = 0; S < (int)(pown[n]); ++S) {
        if (!ok[S]) continue;
        double p = 1;
        for (int i = 0; i < (int)(n); ++i) {
          if (get(S, i) == 2) {
            if (val < L[i])
              p = 0;
            else {
              p *= (min(R[i], val - 1) - L[i] + 1) / W[i];
            }
          } else if (get(S, i) == 1) {
            if (L[i] <= val && val <= R[i]) {
              p /= W[i];
            } else
              p = 0;
          } else {
            if (val > R[i])
              p = 0;
            else {
              p *= (R[i] - max(L[i], val + 1) + 1) / W[i];
            }
          }
        }
        ans += p * val;
      }
    }
    printf("%.15f\n", ans);
  }
}
