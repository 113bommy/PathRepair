#include <bits/stdc++.h>
using namespace std;
int stmp;
const int MAX = 100000;
const int INF = 1000000001;
const long double sin72 = sin(72.0 * M_PI / 180.0);
const long double cos72 = cos(72.0 * M_PI / 180.0);
const long double h = 5.0 * sqrt(5.0 + 2.0 * sqrt(5.0));
vector<pair<long double, long double> > points;
vector<vector<int> > stars;
vector<int> res;
int n;
void solve(int ind, int left) {
  if (left == 0) return;
  vector<int> star;
  star.push_back(ind);
  pair<long double, long double> p = points[ind];
  star.push_back(points.size());
  points.push_back(make_pair(p.first + 10.0, p.second));
  star.push_back(points.size());
  points.push_back(
      make_pair(p.first + 10.0 + 10.0 * cos72, p.second + 10.0 * sin72));
  star.push_back(points.size());
  points.push_back(make_pair(p.first + 5.0, p.second + h));
  star.push_back(points.size());
  points.push_back(make_pair(p.first - 10.0 * cos72, p.second + 10.0 * sin72));
  stars.push_back(star);
  res.push_back(star[3]);
  solve(ind + 3, left - 1);
  res.push_back(star[1]);
  res.push_back(star[4]);
  res.push_back(star[2]);
  res.push_back(star[0]);
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin >> n;
  points.push_back(make_pair(0.0, 0.0));
  res.push_back(0);
  solve(0, n);
  cout.precision(11);
  cout << points.size() << endl;
  for (__typeof((points).begin()) p = (points).begin(); p != (points).end();
       ++p)
    cout << fixed << (p->first) << ' ' << (p->second) << '\n';
  for (int i = 0; i < (n); ++i) {
    for (__typeof((stars[i]).begin()) it = (stars[i]).begin();
         it != (stars[i]).end(); ++it)
      cout << (*it) + 1 << ' ';
    cout << '\n';
  }
  for (__typeof((res).begin()) it = (res).begin(); it != (res).end(); ++it)
    cout << (*it) + 1 << ' ';
  cout << '\n';
  return 0;
}
