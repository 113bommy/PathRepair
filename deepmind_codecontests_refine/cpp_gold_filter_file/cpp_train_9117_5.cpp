#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    double sm = 0.0;
    vector<double> d(250);
    for (int i = 0; i < 250; i++) {
      scanf("%lf", &d[i]);
      sm += d[i];
    }
    double mu = sm / 250.0;
    double sigma2 = 0;
    for (int i = 0; i < 250; i++) {
      sigma2 += pow(d[i] - mu, 2);
    }
    sigma2 /= 250.0;
    if (min(mu, sigma2) / max(mu, sigma2) >= 0.6) {
      cout << int(mu) << endl;
    } else {
      sort(d.begin(), d.end());
      cout << int(d[0] + d[249]) / 2 << endl;
    }
  }
  return 0;
}
