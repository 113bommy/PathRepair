#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e8;
const double pi = 3.1415926535897;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
struct edge {
  int from, to, w;
  edge() {}
  edge(int x, int y, int we) : from(x), to(y), w(we) {}
  bool operator<(const edge &rhs) const { return w > rhs.w; }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> vals;
  for (int i = 0; i < k + 1; i++) {
    cout << "? ";
    for (int j = 0; j < k + 1; j++) {
      if (i == j) continue;
      cout << j + 1 << (j != k ? " " : "");
    }
    cout << endl;
    cout.flush();
    int pos, val;
    cin >> pos >> val;
    vals.push_back(val);
  }
  sort(((vals).begin()), ((vals).end()));
  for (int i = 0; i < k; i++) {
    if (vals[i] != vals[i + 1]) return cout << "! " << k - i << endl, 0;
  }
}
