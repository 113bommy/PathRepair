#include <bits/stdc++.h>
using namespace std;
double PI = 3.141592653589793;
const double EPS = 1e-9;
const int N = 1e6 + 5;
const long long mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
string s1, s2;
vector<int> v;
int GCD(int a, int b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s1 >> s2;
  int g = GCD(s1.size(), s2.size());
  v.push_back(1);
  for (int i = 2; i * i <= g; i++) {
    if (g % i == 0) {
      v.push_back(i);
      if (g / i != i) v.push_back(g / i);
    }
  }
  if (g != 1) v.push_back(g);
  int ans = 0;
  for (int k = 0; k < v.size(); k++) {
    bool ok = 1;
    int cnt = 0;
    for (int i = 0; i < s1.size() && ok; i++) {
      if (s1[cnt] != s1[i]) ok = 0;
      cnt++;
      cnt %= v[k];
    }
    cnt = 0;
    for (int i = 0; i < s2.size() && ok; i++) {
      if (s2[cnt] != s2[i]) ok = 0;
      cnt++;
      cnt %= v[k];
    }
    if (ok) ans++;
  }
  cout << ans;
}
