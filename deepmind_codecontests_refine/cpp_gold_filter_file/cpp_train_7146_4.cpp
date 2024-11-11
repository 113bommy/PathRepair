#include <bits/stdc++.h>
using namespace std;
vector<int> z;
vector<int> pr;
vector<vector<int>> ans;
int s, f;
long long pow(long long n, long long s) {
  if (s == 0)
    return 1;
  else {
    if (s % 2 == 1) {
      return (n * (pow(n, s - 1))) % 1000000007;
    }
    if (s % 2 == 0) {
      long long k = (pow(n, s / 2)) % 1000000007;
      return (k * k) % 1000000007;
    }
  }
}
void prfix(string s) {
  for (int i = 1; i < s.size(); i++) {
    pr[i] = pr[i - 1];
    while (pr[i] > 0 && s[i] != s[pr[i]]) {
      pr[i] = pr[pr[i] - 1];
    }
    if (s[i] == s[pr[i]]) pr[i]++;
  }
}
void zet(string s) {
  int l = 0, r = 0;
  for (int i = 1; i < s.size(); i++) {
    if (i <= r) {
      z[i] = min(z[i - l], r - i + 1);
    }
    for (; z[i] + i < s.size() && s[z[i] + i] == s[z[i]]; z[i]++)
      ;
    if (i + z[i] - 1 >= r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long double R, x1, y1, x2, y2;
  cin >> R >> x1 >> y1 >> x2 >> y2;
  if (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) >= R) {
    cout << x1 << " " << y1 << " " << R;
    return 0;
  }
  if (x1 == x2 && y1 == y2) {
    long double y3 = y1 + R / 2;
    cout << x1 << " " << y3 << " " << R / 2;
    return 0;
  }
  long double c = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  long double x4 = (x1 - x2) * (R + c) / 2 / c + x2;
  long double y4 = (y1 - y2) * (R + c) / 2 / c + y2;
  cout.precision(10);
  cout << fixed << x4 << " " << y4 << " " << (R + c) / 2;
}
