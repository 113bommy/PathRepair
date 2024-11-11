#include <bits/stdc++.h>
using namespace std;
const double pie1 = 3.1415926;
const double pie2 = 3.14159265358979;
const double pie3 = 3.14159265358979323846;
const double pie4 = 3.1415926535897932384626433832795;
const double pie5 =
    3.141592653589793238462643383279502884197199399372505820979944;
const int vbi = 999999999;
const int vli = -vbi;
const long long vbl = 999999999999999999;
const long long vll = -vbl;
const int minn = vli;
const long long minx = vll;
const int maxn = vbi;
const long long maxx = vli;
bool pss(int a) {
  for (int i = 2; i <= sqrt(a); i++)
    if (a % i == 0) return false;
  return true;
}
int pp[11000][30];
int main() {
  ios::sync_with_stdio(false);
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 1; i <= 26; i++) pp[s1.size()][i] = -1;
  for (int i = s1.size() - 1; i >= 0; i--) {
    for (int j = 1; j <= 26; j++) pp[i][j] = pp[i + 1][j];
    pp[i][s1[i] - 96] = i;
  }
  for (int i = 0; i < s2.size(); i++)
    if (pp[0][s2[i] - 96] == -1) {
      cout << -1;
      return 0;
    }
  int ans = 0, sum = 0;
  for (int i = 0; i < s2.size(); i++) {
    if (pp[ans][s2[i] - 96] == -1) {
      sum++;
      ans = pp[0][s2[i] - 96] + 1;
    } else
      ans = pp[ans][s2[i] - 96] + 1;
  }
  cout << sum;
  return 0;
}
