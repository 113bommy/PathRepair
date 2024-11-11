#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, ll> state;
typedef vector<vector<ll>> matrix;

int x[100005];
int y[100005];
string d[100005];
int n;

double getArea(double t) {
  double xMax = -1e9;
  double xMin = 1e9;
  double yMax = -1e9;
  double yMin = 1e9;
  for(int i = 0; i < n; i++) {
    double xx = x[i];
    double yy = y[i];
    if(d[i] == "R") xx += t;
    if(d[i] == "L") xx -= t;
    if(d[i] == "U") yy += t;
    if(d[i] == "D") yy -= t;
    xMax = max(xMax, xx);
    xMin = min(xMin, xx);
    yMax = max(yMax, yy);
    yMin = min(yMin, yy);
  }
  return (xMax-xMin) * (yMax-yMin);
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> d[i];
  double lhs = 0;
  double rhs = 2e8;
  double ret = solve(0);
  for(int qq = 0; qq < 200; qq++) {
    double a = (2*lhs+rhs)/3;
    double b = (2*rhs+lhs)/3;
    ret = min(ret, getArea(a));
    ret = min(ret, getArea(b));
    if(getArea(a) <= getArea(b)) rhs = b;
    else lhs = a;
  }
  cout << fixed << setprecision(10) << ret << "\n";
}

void casesolve() {
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
