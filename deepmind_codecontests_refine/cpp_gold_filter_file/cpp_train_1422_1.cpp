#include <bits/stdc++.h>
#pragma warning(disable : 4996)
FILE *in = stdin, *out = stdout;
using namespace std;
#pragma comment(linker, "/stack:36777216")
int n, T;
double ans;
struct LIST {
  long long int x, t;
  bool operator()(const LIST &A, const LIST &B) { return A.t < B.t; }
} a[300005];
void input() {
  fscanf(in, "%d", &n), fscanf(in, "%d", &T);
  for (int i = (1); i <= (n); i++) fscanf(in, "%lld", &a[i].x);
  for (int i = (1); i <= (n); i++) fscanf(in, "%lld", &a[i].t), a[i].t -= T;
  sort(a + 1, a + 1 + n, LIST());
}
void pro() {
  long long int result = 0;
  if (a[1].t > 0 || a[n].t < 0) {
    fprintf(out, "0.0");
    return;
  }
  for (int i = (1); i <= (n); i++) result += a[i].x * a[i].t, ans += a[i].x;
  if (result > 0) {
    for (int i = n; i >= 1 && result > 0 && a[i].t > 0; i--) {
      if (result >= a[i].x * a[i].t) {
        result -= a[i].x * a[i].t;
        ans -= a[i].x;
      } else {
        ans -= (double)result / a[i].t;
        result = 0;
        break;
      }
    }
  } else if (result < 0) {
    for (int i = 1; i <= n && result < 0 && a[i].t < 0; i++) {
      if (result - a[i].x * a[i].t <= 0) {
        result -= a[i].x * a[i].t;
        ans -= a[i].x;
      } else {
        ans -= (double)result / a[i].t;
        result = 0;
        break;
      }
    }
  }
  fprintf(out, "%.7lf", ans);
}
int main() {
  input();
  pro();
  return 0;
}
