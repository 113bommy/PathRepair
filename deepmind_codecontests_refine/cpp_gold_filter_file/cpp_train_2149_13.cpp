#include <bits/stdc++.h>
using namespace std;
const long long E = (long long)1e9 + 7;
const int N = 100001;
vector<int> g[N];
int a[N] = {0};
int b[N] = {0};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  cout << floor((t + 1) / 2.0) * ceil((t + 1) / 2.0);
  return 0;
}
