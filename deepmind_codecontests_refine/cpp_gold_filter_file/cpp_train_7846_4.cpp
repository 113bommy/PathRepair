#include <bits/stdc++.h>
using namespace std;
long long n, i, answer, m, apb, apc, bpc, same;
vector<long long> v;
int k, j;
int main() {
  cin >> n;
  if (n % 3LL) {
    cout << 0 << endl;
    return 0;
  }
  n /= 3LL;
  for (i = 2LL; i * i <= n; i += 1LL)
    if (n % i == 0LL) {
      v.push_back(i);
      if ((i * i) != n) v.push_back(n / i);
    }
  sort(v.begin(), v.end());
  for (j = 0; j < v.size() && v[j] * v[j] * v[j] <= n; j++) {
    apb = v[j];
    m = n / apb;
    for (k = 0; k < v.size() && v[k] * v[k] <= m; k++)
      if (m % v[k] == 0LL)
        if ((m / v[k]) > 1LL) {
          apc = v[k];
          bpc = m / v[k];
          if (apb <= apc && apc <= bpc)
            if ((apb + apc) > bpc)
              if ((apb + apc + bpc) % 2LL == 0LL) {
                if (apb == apc && apc == bpc)
                  answer += 1LL;
                else if (apb == apc)
                  answer += 3LL;
                else if (apc == bpc)
                  answer += 3LL;
                else
                  answer += 6LL;
              }
        }
  }
  cout << answer << endl;
  return 0;
}
