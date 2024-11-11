#include <bits/stdc++.h>
using namespace std;
int main() {
  int32_t c1, c2, c3, c4;
  int32_t n, m;
  vector<int32_t> buses;
  vector<int32_t> trolleys;
  cin >> c1 >> c2 >> c3 >> c4;
  cin >> n >> m;
  for (int32_t i = 0; i < n; i++) {
    int32_t a;
    cin >> a;
    buses.push_back(a);
  }
  for (int32_t i = 0; i < m; i++) {
    int32_t b;
    cin >> b;
    trolleys.push_back(b);
  }
  int32_t p1 = 0;
  for (int32_t i = 0; i < n; i++) {
    p1 = min(buses[i] * c1, c2);
  }
  p1 = min(c3, p1);
  int32_t p2 = 0;
  for (int32_t i = 0; i < m; i++) {
    p2 = min(trolleys[i] * c1, c2);
  }
  p2 = min(c3, p2);
  cout << min(c4, p1 + p2) << '\n';
}
