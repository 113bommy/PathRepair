#include <bits/stdc++.h>
using namespace std;
long long a, b, c, n, man, mix, x, y, z, k, ans, ans1, l, r, l1, r1, d[1000000],
    d1[10000];
string s, s1, s2, s3;
vector<long long> v, v1;
map<long long, long long> mp, mp1, mp2;
bool o, bo;
stack<long long> st;
char ch;
int main() {
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> b >> c >> x;
    if (x == 0) {
      if (b > c) {
        cout << 1 << endl;
      } else
        cout << 0 << endl;
      continue;
    }
    if (b > c) {
      if (b - c > x) {
        cout << x + 1 << endl;
      } else
        cout << b + x - (c + (b + x - c) / 2) << endl;
    } else if (c - b >= x) {
      cout << 0 << endl;
    } else
      cout << b + x - (c + (b + x - c) / 2) << endl;
  }
}
