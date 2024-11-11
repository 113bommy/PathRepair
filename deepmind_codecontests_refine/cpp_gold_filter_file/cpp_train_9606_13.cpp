#include <bits/stdc++.h>
using namespace std;
long long PI = acos(-1.0), MOD = 1000000007;
long long n, m, x, y, z, k, sol, sum, ans, l, r, xx, yy;
long long a[1000000], b[1000000], mem[1000][1000];
vector<long long> v;
vector<long long> v1;
vector<long long> v2;
vector<pair<long long, long long> > vp;
map<long long, long long> ma;
string s1, s2, s;
set<long long> st;
char c;
int main() {
  cin >> m;
  while (m--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sum = 0;
    for (int i = 0; i < n; i++) {
      bitset<40> x = a[i];
      for (int q = 0; q <= 32; q++) {
        b[q] += x[q];
      }
    }
    sort(a, a + n);
    reverse(a, a + n);
    for (int i = 0; i < n; i++) {
      bitset<40> x = a[i];
      for (int q = 32; q >= 0; q--) {
        if (x[q]) {
          sum += b[q] - 1;
          break;
        }
      }
      for (int q = 0; q <= 32; q++) {
        b[q] -= x[q];
      }
    }
    cout << sum << endl;
  }
  return 0;
}
