#include <bits/stdc++.h>
using namespace std;
const int OO = (int)1e9 + 10;
const double EPS = (1e-7);
int dcmp(double x, double y) { return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1; }
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dx1[] = {0, 0, 1, -1};
int dy1[] = {1, -1, 0, 0};
vector<vector<char> > grid;
vector<vector<bool> > vis;
vector<vector<pair<int, int> > > adjList;
vector<vector<int> > adj;
vector<bool> visited;
template <typename T1, typename T2>
struct less_second {
  bool operator()(pair<T1, T2> const& a, pair<T1, T2> const& b) const {
    return a.second < b.second;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<pair<int, int> > v;
  long long n, t, cnt = 0, tot = 0;
  cin >> n;
  if (n % 2 == 0)
    cout << "white\n"
            "1 2";
  else
    cout << "black";
  return 0;
}
