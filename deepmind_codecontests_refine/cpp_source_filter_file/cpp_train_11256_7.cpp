#include <bits/stdc++.h>
using namespace std;
priority_queue<long long int, vector<long long int>, greater<long long int> > q,
    t;
map<pair<long long int, long long int>, long long int> mp;
vector<long long int> p[150005], v(200005, 0);
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  float n, s;
  cin >> n >> s;
  long long int x, y;
  for (long long int i = 1; i < n; i++) {
    cin >> x >> y;
    p[x].push_back(y);
    p[y].push_back(x);
  }
  float c = 0;
  for (long long int i = 1; i < n; i++) {
    if (p[i].size() == 1) {
      c++;
    }
  }
  cout << fixed << setprecision(6) << (s / c) * 2 << endl;
}
