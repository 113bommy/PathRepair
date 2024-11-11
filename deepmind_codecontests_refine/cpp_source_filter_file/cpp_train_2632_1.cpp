#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> divs;
int main() {
  cin >> n;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      divs.push_back(i);
      divs.push_back(n / i);
    }
  }
  sort(divs.begin(), divs.end());
  long long mini = 1000000000, maxi = 0;
  for (int i = 0; i < divs.size(); ++i)
    for (int j = 0; j <= i && divs[i] * divs[j] <= n; ++j)
      if (n % (divs[i] * divs[j]) == 0) {
        long long k = n / divs[i] / divs[j];
        long long val = (k + 1) * (divs[i] + 2) * (divs[j] + 2) - n;
        mini = min(mini, val);
        maxi = max(maxi, val);
      }
  cout << mini << ' ' << maxi << endl;
}
