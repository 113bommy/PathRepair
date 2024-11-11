#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<long long> divisors, notlovely;
  for (long long i = 2; i <= 1e6 + 5; ++i) notlovely.push_back(i * i);
  long long n;
  cin >> n;
  for (int i = 1; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      divisors.push_back(i);
      divisors.push_back(n / i);
    }
  }
  sort(divisors.begin(), divisors.end());
  int i;
  for (i = divisors.size() - 1; i >= 0; --i) {
    bool flag = true;
    for (int j = 0; j < notlovely.size(); ++j) {
      if (divisors[i] < notlovely[j]) break;
      if (divisors[i] % notlovely[j] == 0) {
        flag = false;
        break;
      }
    }
    if (flag) break;
  }
  cout << divisors[i] << "\n";
  return 0;
}
