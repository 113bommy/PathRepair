#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const double inf = 1e16 + 5;
int n, m;
double c;
double x[MAXN], p[MAXN];
struct node {
  struct info {
    double sum, best;
    double prefix, suffix;
    info() {}
    info(double x) {
      this->sum = x;
      this->best = x;
      this->prefix = x;
      this->suffix = x;
    }
    info operator+(info other) {
      info output;
      output.sum = this->sum + other.sum;
      output.best =
          max(max(this->best, other.best), this->suffix + other.prefix);
      output.prefix = max(this->prefix, this->sum + other.prefix);
      output.suffix = max(this->suffix, other.sum + this->suffix);
      return output;
    }
  };
  info val;
  int l, r;
  node *L, *R;
  node() {}
  node(int l, int r) {
    this->l = l;
    this->r = r;
    this->L = nullptr;
    this->R = nullptr;
  }
  void build() {
    if (this->l == this->r) {
      this->val = info((x[this->l + 1] - x[this->l]) * 0.5 - p[this->l] * c);
      return;
    }
    this->L = new node(this->l, (this->l + this->r) / 2);
    this->R = new node((this->l + this->r) / 2 + 1, this->r);
    this->L->build();
    this->R->build();
    this->val = this->L->val + this->R->val;
  }
  info query(int ql, int qr) {
    if (this->l >= ql && this->r <= qr) return this->val;
    if (this->r < ql || this->l > qr) return info(0);
    return this->L->query(ql, qr) + this->R->query(ql, qr);
  }
};
node *T;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  double answer = 0;
  cin >> n >> m >> c;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> p[i];
    p[i] /= 100.0;
  }
  T = new node(0, n - 2);
  T->build();
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    answer += max(T->query(a, b - 1).best, 0.0);
  }
  cout << fixed << setprecision(7) << answer << '\n';
}
