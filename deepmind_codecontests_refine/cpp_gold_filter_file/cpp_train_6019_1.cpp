#include <bits/stdc++.h>
using namespace std;

int main()
{
  const int mod = 1000000007;
  int n, patterns = 1, prev = 0;
  cin >> n;
  vector<int> p(200001);
  for (int i = 0; i < n; i++) {
    int c, w;
    cin >> c;
    if (c == prev) continue;
    w = (patterns + p.at(c)) % mod;
    patterns = w;
    p.at(c) = w;
    prev = c;
  }
  cout << patterns << endl;
}
