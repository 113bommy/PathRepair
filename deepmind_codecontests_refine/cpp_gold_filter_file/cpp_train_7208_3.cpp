#include <bits/stdc++.h>
using namespace std;
const int mxn = 200009;
long long a[mxn], b[mxn], c[mxn];
long long q, n, m, d, w, k, l, r, sum, sum1, sum2, sum3;
pair<long long, long long> p[mxn];
bool flag, flag1, flag2, flag3, ff;
bool mem[109][109][10009];
bool visited[109][109][10009];
vector<long long> v;
map<long long, long long> mp;
map<long long, long long> mp1;
long long frg[200009];
string s, s1;
int main() {
  cin >> q;
  while (q--) {
    cin >> n >> m >> k;
    sum = n / k;
    if (m == 0) {
      cout << m << endl;
      continue;
    }
    if (sum >= m) {
      cout << m << endl;
      continue;
    }
    if (m > sum) {
      sum1 = m - sum;
      if (sum1 % (k - 1) == 1) {
        sum3 = sum1 / (k - 1) + 1;
        if (sum3 > sum) {
          cout << 0 << endl;
          continue;
        }
      }
      if (sum1 % (k - 1) == 0) {
        sum3 = sum1 / (k - 1);
        if (sum3 > sum) {
          cout << 0 << endl;
          continue;
        }
      }
      if (k - 1 == 1) {
        cout << sum - (m - sum) << endl;
        continue;
      }
      if (sum1 % (k - 1) == 0)
        cout << sum - (sum1 / (k - 1)) << endl;
      else
        cout << sum - ((sum1 / (k - 1)) + 1) << endl;
    }
  }
}
