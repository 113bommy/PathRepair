#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long k, n, s, p;
  cin >> k >> n >> s >> p;
  cout << (k * ((s + n - 1) / n) + p - 1) / p;
}
