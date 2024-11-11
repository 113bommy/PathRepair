#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * (b / (gcd(a, b))); }
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
inline long long toLL(string s) {
  long long v;
  istringstream sin(s);
  sin >> v;
  return v;
}
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
using namespace std;
int ptr = 0;
int N, E;
vector<pair<pair<int, int>, int> > res;
vector<pair<pair<int, int>, int> > edges;
pair<int, int> arr[100000 + 1];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> N >> E;
  int s = 1;
  int e = 2;
  int w, d;
  for (int i = 0; i < (int)E; i++) {
    cin >> w >> d;
    edges.push_back(make_pair(make_pair(w, d * -1), i));
  }
  sort(((edges).begin()), ((edges).end()));
  ptr = 1;
  for (int i = 0; i < E; i++) {
    if (edges[i].first.second == -1) {
      res.push_back(make_pair(make_pair(0, ptr++), edges[i].second));
    } else {
      if (s == e) {
        e++;
        s = 1;
      }
      if (ptr <= e) {
        cout << "-1"
             << "\n";
        return 0;
      }
      res.push_back(make_pair(make_pair(s++, e), edges[i].second));
    }
  }
  for (int i = 0; i < ((int)((res).size())); i++) {
    arr[res[i].second] = make_pair(res[i].first.first, res[i].first.second);
  }
  for (int i = 0; i < (int)E; i++)
    cout << arr[i].first + 1 << " " << arr[i].second + 1 << "\n";
}
