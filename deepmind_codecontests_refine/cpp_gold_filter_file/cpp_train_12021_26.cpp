#include <bits/stdc++.h>
using namespace std;
bool have_solution_better_than(vector<int>& x, vector<int>& b, int l, float r,
                               vector<int>* tb) {
  int n = x.size();
  vector<double> smallest_frustration(n);
  for (int(i) = 0; (i) < (n); (i)++) {
    smallest_frustration[i] = sqrt(abs(x[i] - l)) - r * b[i];
    if (tb) {
      (*tb)[i] = -1;
    }
  }
  for (int(i) = 0; (i) < (n); (i)++) {
    for (int(j) = 0; (j) < (i); (j)++) {
      double t =
          smallest_frustration[j] + sqrt(abs(x[i] - x[j] - l)) - r * b[i];
      if (t < smallest_frustration[i]) {
        smallest_frustration[i] = t;
        if (tb) {
          (*tb)[i] = j;
        }
      }
    }
  }
  return smallest_frustration.back() < 0;
}
void solve() {
  int n, l;
  cin >> n >> l;
  vector<int> x(n), b(n);
  for (int(i) = 0; (i) < (n); (i)++) {
    cin >> x[i] >> b[i];
  }
  double low = 0, high = sqrt(x.back()) + 1;
  while (high - low > 1e-8) {
    double m = (low + high) / 2;
    if (have_solution_better_than(x, b, l, m, 0)) {
      high = m;
    } else {
      low = m;
    }
  }
  vector<int> tb(n);
  have_solution_better_than(x, b, l, (low + high) / 2, &tb);
  vector<int> ans = {n - 1};
  while (ans.back() != -1) {
    ans.push_back(tb[ans.back()]);
  }
  ans.pop_back();
  for (int i = 0; i < (int)(ans).size(); i++)
    cout << ans[ans.size() - i - 1] + 1 << " ";
}
int main() {
  solve();
  return 0;
}
