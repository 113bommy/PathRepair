#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
const int SQRT = 1000;
int n;
vector<pair<pair<int, int>, int> > points;
bool cmp(const pair<pair<int, int>, int> &a,
         const pair<pair<int, int>, int> &b) {
  if (a.first.second / SQRT != b.first.second / SQRT)
    return a.first.second / SQRT < b.first.second / SQRT;
  return a.first.first / SQRT < b.first.first / SQRT;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  points.reserve(n);
  int a, b;
  for (int(i) = (0); (i) < (n); (i)++) {
    cin >> a >> b;
    a++;
    b++;
    points.push_back(make_pair(make_pair(a, b), i + 1));
  }
  sort((points).begin(), (points).end(), cmp);
  for (auto &p : (points)) {
    cout << p.second << ' ';
  }
  cout << "\n";
}
