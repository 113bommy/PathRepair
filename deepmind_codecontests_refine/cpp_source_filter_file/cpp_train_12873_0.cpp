#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int i, j;
  int k, n, s, p;
  cin >> k >> n >> s >> p;
  cout << ceil((ceil(n / (s * 1.0)) * k) / (p * 1.0));
  return 0;
}
