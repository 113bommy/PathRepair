#include <bits/stdc++.h>
using namespace std;
const int Max = 200050;
int a[Max], b[Max];
bool vis[Max];
vector<vector<pair<int, int> > > v(Max);
pair<int, int> p[Max];
map<int, int> x, y;
map<pair<int, int>, int> xy;
vector<pair<int, int> > vv;
int main() {
  long long n, k, alpha[26] = {}, sum = 0, c = 0;
  cin >> n >> k;
  char ch;
  for (int i = 0; i < n; i++) {
    cin >> ch;
    alpha[ch - 'A']++;
  }
  sort(alpha, alpha + 26, greater<int>());
  while (k != 0) {
    sum = sum + min(alpha[c], k) * min(alpha[c], k);
    k -= min(k, alpha[c]);
    c++;
  }
  cout << sum;
  return 0;
}
