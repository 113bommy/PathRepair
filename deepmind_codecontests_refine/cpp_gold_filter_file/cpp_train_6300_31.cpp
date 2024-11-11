#include <bits/stdc++.h>
using namespace std;
const int N = 111;
const long long INF = 1e9 + 19;
int n;
double p[N];
int x[N];
double prob[N];
double pref[N];
double suf[N];
void read() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  int tmp = 0;
  for (int i = 0; i < n; i++) tmp += x[i];
  assert(tmp == 100);
}
double binPow(double x, int b) {
  double res = 1;
  for (; b > 0; b /= 2) {
    if (b & 1) res = res * x;
    x *= x;
  }
  return res;
}
void solve() {
  double answer = 0;
  sort(x, x + n);
  vector<pair<int, int> > b;
  for (int i = 0; i < n;) {
    int j = i;
    for (; i < n && x[i] == x[j]; i++)
      ;
    b.push_back(make_pair(x[j], i - j));
  }
  int m = b.size();
  for (int i = 0; i < m; i++) p[i] = b[i].first / 100.0;
  for (int i = 0; i < m; i++) prob[i] = p[i];
  double mul = 1;
  for (int i = 0; i < m; i++) mul *= binPow(p[i], b[i].second);
  answer += n * mul;
  double sum = mul;
  int t;
  for (t = n + 1;;) {
    int id = -1;
    double best = -1;
    double mulAll = 1;
    for (int i = 0; i < m; i++) {
      mulAll *= binPow(prob[i], b[i].second);
    }
    if (mulAll > 1 - 1e-11) break;
    for (int i = 0; i < m; i++) {
      double cur = mulAll / prob[i] * (1 - prob[i]) * p[i];
      if (best < cur) {
        best = cur;
        id = i;
      }
    }
    double nprob = prob[id] + (1 - prob[id]) * p[id];
    for (int j = 0; j < b[id].second; j++, t++) {
      answer += best * t;
      sum += best;
      best /= prob[id];
      best *= nprob;
    }
    prob[id] = nprob;
  }
  fprintf(stderr, "%.80f\n", (double)sum);
  printf("%.17f\n", (double)answer);
}
void stress() {}
int main() {
  if (1) {
    int k = 1;
    for (int tt = 0; tt < k; tt++) {
      read();
      solve();
    }
  } else {
    stress();
  }
  return 0;
}
