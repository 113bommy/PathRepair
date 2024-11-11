#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int INF = 1000000001;
const float PI = 3.14;
typedef map<string, int> msi;
typedef vector<pair<int, int> > vii;
typedef priority_queue<pair<int, int>, vector<pair<int, int> >,
                       greater<pair<int, int> > >
    pq;
vector<pair<int, int> >::iterator iter;
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    int x[100005];
    int y[100005];
    int f1, f2, f3, f4;
    int MAXY = INF;
    int MINY = -INF;
    int MAXX = INF;
    int MINX = -INF;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i] >> f1 >> f2 >> f3 >> f4;
      if (f2 == 0) {
        MAXY = min(MAXY, y[i]);
      }
      if (f4 == 0) {
        MINY = max(MINY, y[i]);
      }
      if (f3 == 0) {
        MAXX = min(MAXX, x[i]);
      }
      if (f1 == 0) {
        MINX = max(MINX, x[i]);
      }
    }
    if (MINX <= MAXX && MINY <= MAXY) {
      cout << "1 " << MINX << " " << MINY << '\n';
    } else
      cout << "0" << '\n';
  }
  return 0;
}
