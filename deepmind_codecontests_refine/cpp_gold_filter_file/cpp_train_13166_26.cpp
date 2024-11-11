#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, n, m, z, c, t;
  long long b[266] = {0};
  map<long long, long long> a[256];
  string s;
  for (i = 97; i < 123; i++) {
    cin >> b[i];
  }
  cin >> s;
  n = s.size();
  c = 0, z = 0;
  for (i = 0; i < n; i++) {
    z = z + a[s[i]][c];
    c = c + b[s[i]];
    a[s[i]][c] += 1;
  }
  cout << z << endl;
}
