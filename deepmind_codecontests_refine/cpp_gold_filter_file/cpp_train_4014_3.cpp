#include <bits/stdc++.h>
using namespace std;
const int MAX = 410;
int x, y, n, d;
int xi, yi;
int a[MAX][MAX];
vector<pair<int, int> > v;
pair<int, int> p;
void asdfasdf(int x, int y, int val) { a[x + 200][y + 200] = val; }
int get(int x, int y) { return a[x + 200][y + 200]; }
bool check(int x, int y) {
  if (x * x + y * y > d * d) return 1;
  if (get(x, y) >= 0) return get(x, y);
  for (int i = 0; i < n; i++)
    if (check(x + v[i].first, y + v[i].second) == 0) {
      asdfasdf(x, y, 1);
      return 1;
    }
  asdfasdf(x, y, 0);
  return 0;
}
int main() {
  cin >> x >> y >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> xi >> yi;
    p.first = xi;
    p.second = yi;
    v.push_back(p);
  }
  for (int i = -200; i < 203; i++)
    for (int j = -200; j < 203; j++) asdfasdf(i, j, -1);
  if (check(x, y))
    cout << "Anton";
  else
    cout << "Dasha";
}
