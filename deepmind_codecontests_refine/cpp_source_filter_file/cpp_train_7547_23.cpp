#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793238463;
const long long mod = 1000000007;
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U> &l, const std::pair<T, U> &r) {
  return {l.first + r.first, l.second + r.second};
}
struct E {
  int x;
  int y;
  int z;
};
bool cmpf(E &a1, E &a2) {
  if (a1.x != a2.x) return a1.x < a2.x;
  if (a1.y != a2.y) return a1.y < a2.y;
  return a1.z < a2.z;
}
const int N = 100001;
int n, q, l, r;
int x[N];
int a[N];
long long u[N], v[N];
int main() {
  cin >> n >> q;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  for (int i = (1); i <= (n - 1); ++i) x[i] = abs(a[i + 1] - a[i]);
  for (int k = (1); k <= (q); ++k) {
    scanf("%d%d", &l, &r);
    --r;
    stack<int> S, T;
    for (int i = (l); i <= (r); ++i) {
      if (S.size())
        while (S.size() && x[S.top()] < x[i]) S.pop();
      if (S.empty())
        u[i] = i - l + 1;
      else
        u[i] = i - S.top();
      S.push(i);
    }
    for (int i = (r); i >= (l); --i) {
      if (T.size())
        while (T.size() && x[T.top()] <= x[i]) T.pop();
      if (T.empty())
        v[i] = r - i + 1;
      else
        v[i] = T.top() - i;
      T.push(i);
    }
    long long ans = 0;
    for (int i = (l); i <= (r); ++i) ans += (u[i] * v[i]) * x[i];
    printf("I64d\n", ans);
  }
  return 0;
}
