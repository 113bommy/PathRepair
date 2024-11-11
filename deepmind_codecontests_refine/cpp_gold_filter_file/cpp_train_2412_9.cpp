#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 55;
const int inf = 1e9 + 77;
const int MOD = 1e9 + 7;
const double eps = 1e-7;
map<char, int> mp;
map<int, int> mp2;
vector<int> v;
vector<int> vo;
set<int> c;
int x[MAX];
long long y[MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  long long y = (n - 3) / 2;
  if ((3 + (2 * y)) == n && y > 0)
    cout << 1 << " " << y;
  else
    cout << "NO";
  return 0;
}
