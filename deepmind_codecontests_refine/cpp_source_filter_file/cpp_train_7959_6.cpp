#include <bits/stdc++.h>
using namespace std;
long long distance(pair<long long, long long> a, pair<long long, long long> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
  int N, M;
  cin >> N >> M;
  int a;
  cin >> a;
  vector<pair<long long, long long> > hotels1;
  vector<pair<long long, long long> > hotels2;
  for (int r = 0; r < a; r++) {
    int c, d;
    cin >> c >> d;
    hotels1.push_back(pair<long long, long long>(d + c, c - d));
    hotels2.push_back(pair<long long, long long>(c - d, d + c));
  }
  int b;
  cin >> b;
  vector<pair<long long, long long> > resturants;
  for (int r = 0; r < b; r++) {
    int c, d;
    cin >> c >> d;
    resturants.push_back(pair<long long, long long>(c, d));
  }
  sort(hotels1.begin(), hotels1.end());
  sort(hotels2.begin(), hotels2.end());
  vector<pair<long long, long long> > family(4);
  family[0] = hotels1[0];
  family[1] = hotels1[hotels1.size() - 1];
  family[2] = hotels2[0];
  family[3] = hotels2[hotels2.size() - 1];
  for (int k = 0; k < 4; k++) {
    long long t1 = family[k].first;
    long long t2 = family[k].second;
    if (k < 2) {
      family[k].first = (t1 + t2) / 2;
      family[k].second = (t1 - t2) / 2;
    } else {
      family[k].second = (t1 + t2) / 2;
      family[k].first = (t2 - t1) / 2;
    }
  }
  long long mini = 1000000000000;
  int ind = 0;
  for (int r = 1; r <= b; r++) {
    long long highest = -1;
    for (pair<long long, long long> i : family) {
      highest = max(distance(i, resturants[r - 1]), highest);
    }
    if (mini > highest) {
      mini = highest;
      ind = r;
    }
  }
  cout << mini << endl;
  cout << ind << endl;
  return 0;
}
