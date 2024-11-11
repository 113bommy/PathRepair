#include <bits/stdc++.h>
using namespace std;
int inf_int = 2e9;
long long inf_ll = 2e18;
const double pi = 3.1415926535898;
template <typename T>
void prin(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i];
    if (i < a.size() - 1)
      cout << " ";
    else
      cout << "\n";
  }
}
template <typename T>
void prin(set<T>& a) {
  for (auto it = a.begin(); it != a.end(); it++) {
    cout << *it << " ";
  }
}
template <typename T>
void prin_new_line(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << "\n";
  }
}
template <typename T, typename T1>
void prin_new_line(vector<pair<T, T1> >& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i].first << " " << a[i].second << "\n";
  }
}
int sum_vec(vector<int>& a) {
  int s = 0;
  for (int i = 0; i < a.size(); i++) {
    s += a[i];
  }
  return s;
}
template <typename T>
T max(vector<T>& a) {
  T ans = a[0];
  for (int i = 1; i < a.size(); i++) {
    ans = max(ans, a[i]);
  }
  return ans;
}
template <typename T>
T min(vector<T>& a) {
  T ans = a[0];
  for (int i = 1; i < a.size(); i++) {
    ans = min(ans, a[i]);
  }
  return ans;
}
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
double s_triangle(double x1, double y1, double x2, double y2, double x3,
                  double y3) {
  return abs(((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2);
}
bool overflow(long long a, long long b) {
  if (a * b / b != a) return true;
  return false;
}
int dis(int x, int y, int gfgs, int asd) {
  return (x - gfgs) * (x - gfgs) + (y - asd) * (y - asd);
}
bool okr(int x, int y, int r, int gfgs, int asd, int r1, int x2, int y2,
         int r2) {
  if (r1 < r2) {
    swap(gfgs, x2);
    swap(asd, y2);
    swap(r1, r2);
  }
  if (r < r1 && r > r2) {
    int d = dis(x, y, x2, y2);
    if (sqrt(d) + r2 <= r) {
      int d1 = dis(x, y, gfgs, asd);
      if (sqrt(d1) + r <= r1) {
        return true;
      }
      return false;
    }
    return false;
  }
  if (gfgs == x2 && asd == y2) {
    int d = dis(x, y, x2, y2);
    if (d >= r2 * r2 && sqrt(d) + 2 * r <= r1) {
      return true;
    }
    return false;
  }
  return false;
}
bool peres(int gfgs, int asd, int r1, int x2, int y2, int r2) {
  long long d = dis(gfgs, asd, x2, y2);
  if (0) cout << "\t" << d << endl;
  if (d >= (r1 + r2) * (r1 + r2)) {
    if (0) cout << "1" << endl;
    return false;
  }
  if (r1 < r2) {
    swap(gfgs, x2);
    swap(asd, y2);
    swap(r1, r2);
  }
  if (d >= r1 * r1) {
    if (0) cout << "2" << endl;
    return true;
  }
  if (sqrt(d) + r2 <= r1) {
    if (0) cout << "3" << endl;
    return false;
  }
  if (0) cout << "4" << endl;
  return true;
}
bool okr(int gfgs, int asd, int r1, int x2, int y2, int r2) {
  int d = dis(gfgs, asd, x2, y2);
  if (sqrt(d) + r1 <= r2) {
    return true;
  }
  return false;
}
void solve() {
  int gfgs, asd, r1, R1, x2, y2, r2, R2;
  cin >> gfgs >> asd >> r1 >> R1 >> x2 >> y2 >> r2 >> R2;
  int ans = 0;
  if (!peres(gfgs, asd, r1, x2, y2, r2) && !peres(gfgs, asd, r1, x2, y2, R2) &&
      !okr(gfgs, asd, r1, x2, y2, r2, x2, y2, R2) &&
      !(okr(gfgs, asd, r1, x2, y2, R2) && !okr(gfgs, asd, r1, x2, y2, r2))) {
    ans++;
  }
  if (!peres(gfgs, asd, R1, x2, y2, r2) && !peres(gfgs, asd, R1, x2, y2, R2) &&
      !okr(gfgs, asd, R1, x2, y2, r2, x2, y2, R2) &&
      !(okr(gfgs, asd, R1, x2, y2, R2) && !okr(gfgs, asd, R1, x2, y2, r2))) {
    ans++;
  }
  if (!peres(x2, y2, r2, gfgs, asd, r1) && !peres(x2, y2, r2, gfgs, asd, R1) &&
      !okr(x2, y2, r2, gfgs, asd, r1, gfgs, asd, R1) &&
      !(okr(x2, y2, r2, gfgs, asd, R1) && !okr(x2, y2, r2, gfgs, asd, r1))) {
    ans++;
  }
  if (!peres(x2, y2, R2, gfgs, asd, r1) && !peres(x2, y2, R2, gfgs, asd, R1) &&
      !okr(x2, y2, R2, gfgs, asd, r1, gfgs, asd, R1) &&
      !(okr(x2, y2, R1, gfgs, asd, R1) && !okr(x2, y2, R2, gfgs, asd, r1))) {
    ans++;
  }
  cout << ans;
}
int main() {
  if (!0) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int t = 1;
  while (t--) solve();
  return 0;
}
