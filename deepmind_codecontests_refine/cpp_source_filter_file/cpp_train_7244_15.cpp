#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
double logFact[N];
int main() {
  int maxItr = 250;
  for (int i = 2; i < N; i++) logFact[i] = logFact[i - 1] + log(i);
  int v;
  cin >> v;
  for (int i = 0; i < v; i++) {
    vector<int> vec;
    for (int j = 0; j < maxItr; j++) {
      int x;
      cin >> x;
      vec.push_back(x);
    }
    double maxi = -1E18;
    string ans = "";
    int P = -1;
    for (int k = 1; k <= 1000; k++) {
      double lnP = log(k);
      double ln2P = log(2 * k + 1);
      double poisson = 0;
      double uniform = 0;
      for (int j = 0; j < maxItr; j++)
        if (vec[j] <= k && vec[j] + k >= 0)
          uniform -= ln2P;
        else
          uniform -= 1E18;
      for (int j = 0; j < maxItr; j++) {
        vec[j] += k;
        if (k >= 0)
          poisson += vec[j] * lnP - logFact[vec[j]] - k;
        else
          poisson -= 1E18;
        vec[j] -= k;
      }
      if (poisson > maxi) {
        maxi = poisson;
        P = k;
        ans = "poisson";
      }
      if (uniform > maxi) {
        maxi = uniform;
        P = k;
        ans = "uniform";
      }
    }
    cout << ans << endl;
  }
  return 0;
}
