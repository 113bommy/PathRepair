#include <bits/stdc++.h>
using namespace std;
bool comp(const double &s1, const double &s2) { return s1 < s2; }
int main() {
  long n, x, y;
  double s[200000];
  cin >> n;
  for (long i = 0; i < n; i++) {
    cin >> x >> y;
    s[i] = atan2(x, y) / acos(-1) * 180.0;
  }
  sort(s, &s[n], comp);
  double sb = s[n - 1] - s[0];
  for (long i = 0; i < n - 1; i++)
    if ((360.0 - (s[i + 1] - s[i])) > sb) sb = (360.0 - (s[i + 1] - s[i]));
  printf("%.10lf", sb);
}
