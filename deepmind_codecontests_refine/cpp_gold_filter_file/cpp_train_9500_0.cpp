#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[8];
void read() {
  for (int i = 0; i < 8; i++) cin >> p[i].first >> p[i].second;
}
void write(int mask) {
  printf("YES\n");
  for (int i = 0; i < 8; i++)
    if (!((mask >> i) & 1)) cout << i + 1 << " ";
  cout << endl;
  for (int i = 0; i < 8; i++)
    if ((mask >> i) & 1) cout << i + 1 << " ";
  cout << endl;
}
bool check(pair<int, int> p1, pair<int, int> O, pair<int, int> p2) {
  int x1 = p1.first - O.first;
  int y1 = p1.second - O.second;
  int x2 = p2.first - O.first;
  int y2 = p2.second - O.second;
  return (x1 * x2 + y1 * y2 == 0);
}
bool isRectangle(int mask) {
  vector<pair<int, int> > vec;
  for (int i = 0; i < 8; i++)
    if ((mask >> i) & 1) vec.push_back(p[i]);
  sort(vec.begin(), vec.end());
  do {
    bool fl = true;
    for (int i = 0; i < vec.size(); i++)
      if (!check(vec[(i - 1 + 4) % 4], vec[i], vec[(i + 1) % 4])) {
        fl = false;
        break;
      }
    if (fl) return true;
  } while (next_permutation(vec.begin(), vec.end()));
  return false;
}
int dist(pair<int, int> a, pair<int, int> b) {
  return (a.first - b.first) * (a.first - b.first) +
         (a.second - b.second) * (a.second - b.second);
}
bool isSquare(int mask) {
  vector<pair<int, int> > vec;
  for (int i = 0; i < 8; i++)
    if (!((mask >> i) & 1)) vec.push_back(p[i]);
  sort(vec.begin(), vec.end());
  do {
    bool fl = true;
    int D = dist(vec[0], vec[1]);
    for (int i = 0; i < vec.size(); i++) {
      if (!check(vec[(i - 1 + 4) % 4], vec[i], vec[(i + 1) % 4])) {
        fl = false;
        break;
      }
      if (D != dist(vec[(i - 1 + 4) % 4], vec[i])) {
        fl = false;
        break;
      }
      if (D != dist(vec[i], vec[(i + 1) % 4])) {
        fl = false;
        break;
      }
    }
    if (fl) return true;
  } while (next_permutation(vec.begin(), vec.end()));
  return false;
}
void solve() {
  for (int mask = 0; mask < (1 << 8); mask++)
    if (__builtin_popcount(mask) == 4 && isSquare(mask) && isRectangle(mask)) {
      write(mask);
      return;
    }
  printf("NO\n");
}
int main() {
  read();
  solve();
  return 0;
}
