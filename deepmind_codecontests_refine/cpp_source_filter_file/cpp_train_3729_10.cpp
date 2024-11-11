#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, m;
  cin >> n >> m;
  vector<long> p(m), y(m), count(n), id(m);
  for (int i = 0; i < m; i++) {
    cin >> p.at(i) >> y.at(i);
    y.at(i) = 100000 * y.at(i) + i;
  }
  sort(y.begin(), y.end());
  for (int i = 0; i < m; i++) {
    long order = y.at(i) % 100000;
    count.at(p.at(order))++;
    id.at(order) = 1000000 * p.at(order) + count.at(p.at(order));
  }
  for (int i = 0; i < m; i++) {
    printf("%0.12ld\n", id.at(i));
  }
}
