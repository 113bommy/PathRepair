#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0},  {0, -1},
                        {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
string a, b;
int z1[100004], z2[100004], c[100005], ans;
void z1algo(string s, int n) {
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z1[i] = min(r - i + 1, z1[i - l]);
    while (i + z1[i] < n && s[z1[i]] == s[i + z1[i]]) ++z1[i];
    if (i + z1[i] - 1 > r) l = i, r = i + z1[i] - 1;
  }
}
void z2algo(string s, int n) {
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z2[i] = min(r - i + 1, z2[i - l]);
    while (i + z2[i] < n && s[z2[i]] == s[i + z2[i]]) ++z2[i];
    if (i + z2[i] - 1 > r) l = i, r = i + z2[i] - 1;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> a;
  z1algo(a, a.size());
  int n = a.size();
  int maxp = 0;
  int len;
  for (int i = 1; i < n; i++) {
    if (i + z1[i] == n && z1[i] <= maxp) {
      len = z1[i];
      break;
    }
    maxp = max(maxp, z1[i]);
  }
  if (!min(len, maxp)) {
    cout << "Just a legend\n";
    return 0;
  }
  for (int i = 0; i < min(len, maxp); i++) cout << a[i];
}
