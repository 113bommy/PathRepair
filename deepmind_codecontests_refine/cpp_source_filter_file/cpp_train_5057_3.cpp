#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int n;
  int k;
  cin >> n >> k;
  vector<int> divs;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divs.push_back(i);
      if (n / i != i) divs.push_back(n / i);
    }
  }
  sort(divs.begin(), divs.end());
  if (divs.size() < k)
    cout << -1;
  else
    cout << divs[k - 1];
}
