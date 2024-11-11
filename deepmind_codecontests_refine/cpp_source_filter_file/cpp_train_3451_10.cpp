#include <bits/stdc++.h>
using namespace std;
const int N = 21;
bitset<N> l;
bitset<N> pom;
vector<int> wyn;
int toBin(int a) {
  int i = 0;
  while (a > 0) {
    l[i] = a % 2;
    a /= 2;
    i++;
  }
  return i - 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int m, i, j, x, n = 0, w = 0;
  cin >> x;
  if (x == 1) {
    cout << "0\n";
    return 0;
  }
  if (x == 2) {
    cout << "1\n0";
    return 0;
  }
  m = toBin(x);
  while (i <= m) {
    i = 0, n = 0;
    while (!l[i]) i++, n++;
    wyn.push_back(n);
    for (j = 0; j < n; j++) pom[j] = 1;
    l = l ^ pom;
    i = 0;
    while (l[i]) l[i] = 0, i++;
    l[i] = 1;
  }
  cout << wyn.size() * 2 - 1 << '\n';
  for (i = 0; i < wyn.size(); i++) cout << wyn[i] << ' ';
  return 0;
}
