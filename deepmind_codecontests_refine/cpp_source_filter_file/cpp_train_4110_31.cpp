#include <bits/stdc++.h>
using namespace std;
vector<int> vec{};
int numof(string sing, char x) {
  map<char, int> nuof;
  string a = sing;
  for (char c : a) {
    nuof[c]++;
  }
  return nuof[x];
}
int main() {
  int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y,
      z, count;
  a = b = c = d = e = f = g = h = i = j = k = l = m = n = o = p = q = r = s =
      t = u = v = w = x = y = z = count = 0;
  cin >> a >> b >> c >> d;
  if (max((3 * a) / 10, a - ((a * c) / 250)) <
      max((3 * b) / 10, a - ((b * d) / 250))) {
    cout << "Misha";
  } else if (max((3 * a) / 10, a - ((a * c) / 250)) >
             max((3 * b) / 10, a - ((b * d) / 250))) {
    cout << "Vasya";
  } else {
    cout << "Tie";
  }
}
