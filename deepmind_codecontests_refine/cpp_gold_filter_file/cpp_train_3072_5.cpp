#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x1, x2;
  cin >> n;
  cin >> x1 >> x2;
  pair<long long, long long> pr[100 * 1000];
  for (long long i = 0; i < n; i++) {
    long long k, b;
    cin >> k >> b;
    pr[i] = {k * x1 + b, k * x2 + b};
  }
  sort(pr, pr + n);
  for (long long i = 0; i < n - 1; i++) {
    if (pr[i].second > pr[i + 1].second) {
      cout << "yes";
      return 0;
    }
  }
  cout << "no";
}
