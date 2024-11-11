#include <bits/stdc++.h>
using namespace std;
long long ct[100005];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
int cal(int a, int b) {
  int s = a + b;
  int c = 1;
  int d = 1, e = 1;
  for (int i = 1; i <= s; ++i) {
    c = c * i;
    if (i == a) d = c;
    if (i == b) e = c;
  }
  d = c / (d * e);
  return d;
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int s = 0, t = 0, q = 0;
  for (int i = 0; i < s1.size(); ++i) {
    if (s1[i] == '+') s++;
    if (s2[i] == '+') t++;
    if (s2[i] == '?') q++;
  }
  int d = abs(s - t);
  if (d > q || t > s) {
    cout << 0;
    return 0;
  } else {
    int e = pow(2, q);
    d = cal(d, q - d);
    double ans = d * 1.0;
    ans /= e;
    printf("%.10lf\n", ans);
  }
  return 0;
}
