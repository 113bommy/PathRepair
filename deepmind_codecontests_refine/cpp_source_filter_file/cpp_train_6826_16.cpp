#include <bits/stdc++.h>
using namespace std;
const int OO = (int)2e9;
const double PI = 2 * acos(0);
const double EPS = 1e-9;
int dcmp(double a, double b) { return fabs(a - b) <= EPS ? 0 : a > b ? 1 : 2; }
int DI[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int DJ[] = {0, 1, 0, -1, 1, -1, 1, -1};
int n;
vector<pair<int, string> > v;
int main() {
  scanf("%d", &n);
  int t = n;
  while (t--) {
    string x;
    cin >> x;
    int sum = 0;
    int p, m;
    scanf("%d%d", &p, &m);
    sum += (p * 100);
    sum -= (m * 50);
    for (int i = 0; i < (int)n; i++) {
      cin >> p;
      sum += p;
    }
    v.push_back(make_pair(sum, x));
  }
  sort(v.begin(), v.end());
  cout << v[(int)v.size() - 1].second << endl;
  return 0;
}
