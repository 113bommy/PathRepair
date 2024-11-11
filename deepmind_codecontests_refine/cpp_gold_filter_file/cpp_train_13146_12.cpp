#include <bits/stdc++.h>
using namespace std;
long long a, b, c, n, i, j, res1 = 1e12, res2 = -1e12;
vector<long long> d;
int main() {
  cin >> n;
  for (i = 1; i * i <= n; i++)
    if (n % i == 0) {
      d.push_back(i);
      if (n / i != i) d.push_back(n / i);
    }
  for (i = 0; i < d.size(); i++)
    for (j = 0; j < d.size(); j++) {
      a = d[i];
      b = d[j];
      if (n % (a * b) == 0) {
        c = n / (a * b) + 2;
        a++;
        b += 2;
        res1 = min(res1, a * b * c);
        res2 = max(res2, a * b * c);
      }
    }
  cout << res1 - n << " " << res2 - n << endl;
}
