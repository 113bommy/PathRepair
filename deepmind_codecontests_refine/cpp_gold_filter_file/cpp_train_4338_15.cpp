#include <bits/stdc++.h>
using namespace std;
int best_t(const vector<int>& v, int pos1, int pos2) {
  auto it1 = lower_bound(v.begin(), v.end(), pos1);
  auto it2 = lower_bound(v.begin(), v.end(), pos2);
  if (v.empty()) return 1e9;
  if (it1 != it2) return pos2 - pos1;
  if (it1 == v.end()) return pos1 - v.back() + pos2 - v.back();
  if (it1 == v.begin()) return v.front() - pos1 + v.front() - pos2;
  return min(pos1 - *(it1 - 1) + pos2 - *(it1 - 1), *it1 - pos1 + *it1 - pos2);
}
int main() {
  int H, L, stairs_num, elevators_num, v;
  cin >> H >> L >> stairs_num >> elevators_num >> v;
  vector<int> stairs;
  while (stairs_num--) {
    int pos;
    cin >> pos;
    stairs.push_back(pos);
  }
  vector<int> elevators;
  while (elevators_num--) {
    int pos;
    cin >> pos;
    elevators.push_back(pos);
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int h1, pos1, h2, pos2;
    cin >> h1 >> pos1 >> h2 >> pos2;
    if (h1 > h2) swap(h1, h2);
    if (pos1 > pos2) swap(pos1, pos2);
    if (h1 == h2)
      cout << abs(pos2 - pos1) << endl;
    else
      cout << min(best_t(stairs, pos1, pos2) + h2 - h1,
                  best_t(elevators, pos1, pos2) +
                      (int)ceil(double(h2 - h1) / v))
           << endl;
  }
}
