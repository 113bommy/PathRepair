#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 100;
const double PI = 3.1415926536;
vector<pair<int, int> > v;
long long n, m, k, t, sum, l, r, p, e, d, c, a, b;
long long ans;
bool f;
string s;
set<long long> st;
map<long long, long long> mp;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  while (n--) {
    cin >> a >> b;
    if (a % b == 0)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
