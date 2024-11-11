#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
const long double eps = 1e-9;
const long long INF = 100000000000000;
const int MAXN = 110;
int t, m;
int a[MAXN];
map<int, int> start;
int ids = 0;
int main() {
  cin >> t >> m;
  for (long long query = 1; query <= t; ++query) {
    string s;
    cin >> s;
    if (s == "alloc") {
      int n;
      cin >> n;
      bool done = false;
      for (long long i = 1; i <= m - n + 1; ++i) {
        bool ok = true;
        for (long long j = i; j <= i + n - 1; ++j)
          if (a[j]) {
            ok = false;
            break;
          }
        if (ok) {
          ++ids;
          cout << ids << endl;
          for (long long j = i; j <= i + n - 1; ++j) a[j] = ids;
          start[ids] = i;
          done = true;
          break;
        }
      }
      if (!done) cout << "NULL\n";
    }
    if (s == "erase") {
      int id;
      cin >> id;
      if (start[id] == 0)
        cout << "ILLEGAL_ERASE_ARGUMENT\n";
      else {
        for (long long i = 1; i <= m; ++i)
          if (a[i] == id) a[i] = 0;
        start[id] = 0;
      }
    }
    if (s == "defragment") {
      int mv = 0;
      for (long long i = 1; i <= m; ++i)
        if (a[i] == 0)
          ++mv;
        else {
          a[i - mv] = a[i];
          a[i] = 0;
        }
    }
  }
}
