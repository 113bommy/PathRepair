#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int MX = 2e5 + 9;
int n;
double val[MX];
string s;
char oo[MX];
map<double, int> m;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%s", &oo);
    s = oo;
    double s1 = 0, s2 = 0, s3 = 0;
    int j = 1;
    while (isdigit(s[j])) {
      s1 *= 10;
      s1 += s[j] - '0';
      j++;
    }
    j++;
    while (isdigit(s[j])) {
      s2 *= 10;
      s2 += s[j] - '0';
      j++;
    }
    j += 2;
    while (isdigit(s[j])) {
      s3 *= 10;
      s3 += s[j] - '0';
      j++;
    }
    val[i] = (s1 + s2) / s3;
    m[val[i]]++;
  }
  for (int i = 0; i < n; i++) cout << m[val[i]] << " ";
}
