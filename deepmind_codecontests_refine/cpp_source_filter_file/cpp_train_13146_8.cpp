#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  long long Max = 0, Min = 9223372036854775807LL, p;
  vector<int> x;
  cin >> n;
  for (i = 1; i <= sqrt(n) + 1; i++)
    if (n % i == 0) x.push_back(i), x.push_back(n / i);
  x.push_back(n);
  m = x.size();
  for (i = 0; i < m; i++)
    for (j = 0; j < m; j++) {
      long long b = (long long)(x[i]) * x[j];
      if (n > b && n % b == 0) {
        int l = n / (x[i] * x[j]);
        p = (long long)(x[i] + 1) * (long long)(x[j] + 2);
        p *= (long long)(l + 2);
        p -= n;
        if (p > 0 && p > Max) Max = p;
        if (p > 0 && p < Min) Min = p;
      }
    }
  cout << Min << " " << Max << endl;
  return 0;
}
