#include <bits/stdc++.h>
using namespace std;
vector<vector<double> > prob_;
double eps = 1e-8;
double prob(vector<double> &probs, int K, int l) {
  if (l == ((int)probs.size())) {
    if (K == 0) {
      return 1;
    } else {
      return 0;
    }
  }
  if (prob_[K][l] < -eps) {
    prob_[K][l] = prob(probs, K, l + 1) * (1 - probs[l]);
    if (K > 0) {
      prob_[K][l] += prob(probs, K - 1, l + 1) * (probs[l]);
    }
  }
  return prob_[K][l];
}
double get_prob(int x, int y, double r, int sx, int sy) {
  if ((sx - x) * (sx - x) + (sy - y) * (sy - y) <= r * r) {
    return 1;
  } else {
    return exp(1 - ((sx - x) * (sx - x) + (sy - y) * (sy - y)) / r / r);
  }
}
void solve() {
  int n, k;
  double es;
  cin >> n >> k >> es;
  es /= 1000;
  int x, y;
  cin >> x >> y;
  vector<int> xs(n);
  vector<int> ys(n);
  for (int i = 0; i < n; ++i) {
    cin >> xs[i] >> ys[i];
  }
  double l = 0, r = 1000;
  while (r - l > eps) {
    double m = (l + r) / 2;
    prob_.assign(n + 1, vector<double>(n + 1, -1));
    vector<double> probs(n);
    for (int i = 0; i < n; ++i) {
      probs[i] = get_prob(x, y, m, xs[i], ys[i]);
    }
    double pr = 0;
    for (int i = k; i <= n; ++i) {
      pr += prob(probs, i, 0);
    }
    if (pr > 1 - es) {
      r = m;
    } else {
      l = m;
    }
  }
  cout.precision(15);
  cout << l << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
