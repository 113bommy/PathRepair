#include <bits/stdc++.h>
using namespace std;
struct unit {
  long double val;
  long double p_fail;
  long double p_fail1;
  void recount() { val = p_fail * (1.0 - p_fail1) / (1.0 - p_fail); }
};
bool operator<(const unit& left, const unit& right) {
  return left.val < right.val;
}
int main(int argc, const char* argv[]) {
  int n;
  cin >> n;
  priority_queue<unit> p;
  long double mul_p = 0.0;
  for (int i = 0; i < n; i++) {
    int t;
    unit q;
    cin >> t;
    q.p_fail1 = 1.0 - t * 0.01;
    q.p_fail = 1.0;
    q.val = 1.0;
    p.push(q);
    mul_p += log(1.0 - q.p_fail1);
  }
  long double ret = exp(mul_p) * n;
  long double p1 = exp(mul_p);
  for (int i = 1; i <= 100000; i++) {
    unit t = p.top();
    p.pop();
    if (i > n) {
      mul_p -= log(1.0 - t.p_fail);
      ret += i * exp(mul_p) * t.p_fail * (1.0 - t.p_fail1);
    }
    t.p_fail *= t.p_fail1;
    if (i > n) mul_p += log(1.0 - t.p_fail);
    t.recount();
    p.push(t);
  }
  printf("%.9f\n", (double)ret);
  return 0;
}
