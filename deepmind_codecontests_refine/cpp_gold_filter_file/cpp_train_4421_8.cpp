#include <bits/stdc++.h>
using namespace std;
long long int fact(long long int n) {
  return (n == 1 || n == 0) ? 1 : n * fact(n - 1);
}
long long int nCr(long long int n, long long int r) {
  return fact(n) / (fact(r) * fact(n - r));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long int> v(n);
  int sum = 0;
  for (int i = 0; i < int(n); i++) {
    cin >> v[i];
    sum += v[i];
  }
  int c = 0;
  for (int i = 0; i < int(n); i++) {
    if (v[i] == 1 && v[i + 1] == 1) {
      while (i < n && v[i] == 1) {
        c++;
        i++;
        sum -= 1;
      }
      if (sum != 0) c++;
    } else if (v[i] == 1 && sum != 1) {
      c += 2;
      sum -= 1;
    } else if (v[i] == 1 && sum == 1) {
      c += 1;
    }
  }
  cout << c;
}
