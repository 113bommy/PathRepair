#include <bits/stdc++.h>
using namespace std;
int n, k, b[10], l[10], ll[10];
double A, prob, res;
void counting(int cur, int positive, double t_prob, double B) {
  if (cur == n) {
    prob += (positive > n / 2) ? t_prob : t_prob * (A / (A + B));
    return;
  }
  if (l[cur] == 0) {
    counting(cur + 1, positive, t_prob, B + b[cur]);
    return;
  }
  if (l[cur] == 100) {
    counting(cur + 1, positive + 1, t_prob, B);
    return;
  }
  counting(cur + 1, positive + 1, t_prob * (l[cur] / 100.0), B);
  counting(cur + 1, positive, t_prob * ((100 - l[cur]) / 100.0), B + b[cur]);
}
void make_state(int cur, int rest) {
  if (cur == n) {
    if (rest != 0) return;
    prob = 0;
    counting(0, 0, 1, 0);
    res = max(prob, res);
    return;
  }
  if (rest == 0) {
    make_state(cur + 1, rest);
    return;
  }
  if (l[cur] < 100) {
    l[cur] += 10;
    make_state(cur, rest - 1);
    l[cur] -= 10;
  }
  make_state(cur + 1, rest);
}
int main(int argc, char* argv[]) {
  cin >> n >> k >> A;
  for (int i = 0; i < (int)n; i++) cin >> b[i] >> l[i];
  for (int i = 0; i < (int)n; i++) {
    ll[i] = 10 - (l[i] / 10);
  }
  sort(ll, ll + n);
  int kk = k, cnt = 0;
  for (int i = 0; i < (int)n; i++) {
    if (kk < ll[i]) break;
    kk -= ll[i];
    cnt++;
  }
  if (cnt * 2 >= n) {
    puts("1.0000000");
    return 0;
  }
  make_state(0, k);
  printf("%8f\n", res);
  return 0;
}
