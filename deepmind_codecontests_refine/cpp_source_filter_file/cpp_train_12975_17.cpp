#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  double R;
  cin >> N >> R;
  vector<double> X(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i];
  }
  vector<double> final(N);
  for (int i = 0; i < N; ++i) {
    double h = 2;
    for (int j = 0; j < i; ++j) {
      if (abs(X[j] - X[i]) <= 2 * R) {
        h = max(h, final[j] +
                       sqrt(4 * R * R - abs(X[j] - X[i]) * abs(X[j] - X[i])));
      }
    }
    final[i] = h;
  }
  cout << fixed << setprecision(8);
  for (int i = 0; i < N; ++i) {
    cout << final[i];
    if (i < N - 1)
      cout << " ";
    else
      cout << '\n';
  }
}
