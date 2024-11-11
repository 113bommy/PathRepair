#include <bits/stdc++.h>
using namespace std;
const double EXP = 2.71828182845904523536028;
double p(double r, const vector<pair<int, int> >& objects, int x, int y,
         int K) {
  vector<double> probabilities;
  for (int i = 0; i < objects.size(); ++i) {
    int dist = (objects[i].first - x) * (objects[i].first - x) +
               (objects[i].second - y) * (objects[i].second - y);
    if (r == 0) {
      if (dist == 0)
        probabilities.push_back(1);
      else
        probabilities.push_back(0);
    } else {
      double d = sqrt(double(dist));
      if (d <= r)
        probabilities.push_back(1);
      else
        probabilities.push_back(pow(EXP, 1 - d * d / r / r));
    }
  }
  vector<double> p(probabilities.size() + 1);
  p[0] = 1;
  for (int i = 0; i < probabilities.size(); ++i) {
    vector<double> p_next = p;
    for (int j = 0; j < p.size(); ++j) {
      p_next[j] = p[j] * (1 - probabilities[i]);
      if (j > 0) p_next[j] += p[j - 1] * probabilities[i];
    }
    swap(p_next, p);
  }
  double res = 0;
  for (int i = K; i < p.size(); ++i) {
    res += p[i];
  }
  return res;
}
int main(int argc, char* argv[]) {
  int N, K, eps;
  cin >> N >> K >> eps;
  int x, y;
  cin >> x >> y;
  vector<pair<int, int> > objects;
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    objects.push_back(make_pair(a, b));
  }
  double hi = 2000, low = 0;
  double r;
  const int STEPS = 10000;
  for (int i = 0; i < STEPS; ++i) {
    r = (hi + low) / 2;
    if (p(r, objects, x, y, K) >= (1 - eps / 1000.0))
      hi = r;
    else
      low = r;
  }
  cout << setprecision(16) << r;
}
