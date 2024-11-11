#include <bits/stdc++.h>
using namespace std;
long long j, k, l, m, a, b, c[111], d[111], g, f, t, s, h, e;
long long i, n;
map<long long, long long> x, y;
string p, q, r;
char w;
int main() {
  cin >> p;
  l = p.size();
  while (p[i] != '^') i++;
  for (j = i + 1; j < l; j++) {
    if (p[j] != '=') a += (j - i) * (p[j] - 48);
  }
  for (j = 0; j < i; j++) {
    if (p[j] != '=') b += (i - j) * (p[j] - 48);
  }
  if (a == b) cout << "balanced";
  if (a > b) cout << "right";
  if (a < b) cout << "left";
}
