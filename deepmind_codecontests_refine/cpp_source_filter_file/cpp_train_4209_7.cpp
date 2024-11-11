#include <bits/stdc++.h>
using namespace std;
long long conversion(string p) {
  long long o;
  o = atol(p.c_str());
  return o;
}
string toString(int h) {
  stringstream ss;
  ss << h;
  return ss.str();
}
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
int main() {
  int n, k, x, res = 0, uno = 0, dos = 0;
  cin >> n >> k;
  vector<int> M, N;
  for (int i = 0; i < n; i++) {
    cin >> x;
    M.push_back(x);
  }
  if (k == 1) {
    for (int j = 0; j < M.size(); j++) {
      if (M[j] == 1)
        uno++;
      else
        dos++;
    }
    cout << min(dos, uno) << endl;
    return 0;
  }
  for (int i = 0; i < n / k; i++) {
    for (int j = i; j < M.size(); j += k) {
      if (M[j] == 1)
        uno++;
      else
        dos++;
    }
    res += min(uno, dos);
    uno = 0, dos = 0;
  }
  cout << res << endl;
}
