#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
using ll = long long;
const double PI = 2 * acosl(0);
double get_angle(int distance) {
  return asinl(1.L / sqrt((long double)distance * distance + 1));
}
int main() {
  debug() << " ["
          << "PI"
             ": "
          << (PI) << "] ";
  int n, magic_d;
  scanf("%d%d", &n, &magic_d);
  vector<int> a(n);
  vector<int> s;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    s.push_back(a[i]);
    s.push_back(a[i] + 1);
  }
  sort(s.begin(), s.end());
  s.resize(unique(s.begin(), s.end()) - s.begin());
  int a_i = 0, s_i = 0;
  int q;
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    while (a_i < n && a[a_i] < x) {
      ++a_i;
    }
    while (s_i < (int)s.size() && s[s_i] < x) {
      ++s_i;
    }
    if (a_i == n || a_i == 0) {
      printf("%.10lf\n", PI / 2);
      continue;
    }
    assert(1 <= a_i && a_i <= n - 1);
    assert(a[a_i] >= x);
    if (x == a[a_i] && x == a[a_i - 1] + 1) {
      printf("%.10lf\n", PI);
      continue;
    }
    int distance = min(a[a_i] - x, x - a[a_i - 1] - 1);
    double answer = get_angle(distance);
    int A = s_i - 1;
    for (int B = s_i; B < (int)s.size(); ++B) {
      if (s[B] - x >= 2 * distance) {
        break;
      }
      while (A >= 0 && s[B] - x > x - s[A]) {
        --A;
      }
      if (A < 0) {
        break;
      }
      if (s[B] - x == x - s[A]) {
        answer = max(answer, 2 * get_angle(x - s[A]));
        break;
      }
    }
    printf("%.10lf\n", answer);
  }
}
