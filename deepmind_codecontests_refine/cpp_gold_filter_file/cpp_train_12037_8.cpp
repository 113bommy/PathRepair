#include <bits/stdc++.h>
using namespace std;
int n, sum = 0, m, x;
vector<int> input;
int gcd(int c, int d) {
  if (c < d) switch (c, d)
      ;
  if (d == 0) return c;
  return gcd(d, c % d);
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  cin >> x;
  bool p[x];
  for (int i = 0; i < x; i++) {
    p[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> m;
    input.push_back(m);
    if (m == x) {
      sum++;
    }
  }
  sort(input.begin(), input.end());
  for (int i = 0; i < n; i++) {
    if (input[i] < x) {
      p[input[i]]++;
    }
  }
  for (int i = 0; i < x; i++) {
    if (p[i] == 0) {
      sum++;
    }
  }
  cout << sum << endl;
  return 0;
}
