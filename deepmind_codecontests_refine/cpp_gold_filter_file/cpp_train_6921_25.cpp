#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const long double pi = acos(-1);
vector<int> times;
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  cout << fixed;
  cout.tie(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int(i) = 0, j123 = n; (i) < j123; (i)++) {
    int foo;
    cin >> foo;
    times.push_back(foo);
  }
  sort(times.begin(), times.end());
  long long currentTime = 0;
  int numServed = 0;
  for (int(i) = 0, j123 = n; (i) < j123; (i)++) {
    int hisTime = times[i];
    if (hisTime >= currentTime) {
      currentTime += hisTime;
      numServed++;
    }
  }
  cout << numServed << '\n';
}
