#include <bits/stdc++.h>
using namespace std;
double k, koor, uz;
int i, sayac, n;
pair<double, double> p[1005];
void oku() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    cin >> koor >> uz;
    p[i].first = koor - (uz / 2);
    p[i].second = koor + (uz / 2);
  }
  sort(p + 1, p + n + 1);
}
void coz() {
  if (p[1].first - k >= -1000) sayac++;
  if (p[n].second + k <= 1000) sayac++;
  for (i = 1; i <= n; i++) {
    if (i != 1 && p[i].first - k >= p[i - 1].second) sayac++;
    if (i != n && p[i].second + k <= p[i + 1].first) sayac++;
    if (i > 1 && p[i].first - p[i - 1].second == k) sayac--;
  }
  cout << sayac << endl;
}
int main() {
  oku();
  coz();
  return 0;
}
