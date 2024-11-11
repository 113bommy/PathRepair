#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5;
int n, j;
string f, l;
pair<string, string> p[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> f >> l;
    p[i] = make_pair(f, l);
  }
  string last = "";
  bool ok = true;
  for (int i = 0; i < n && ok; i++) {
    cin >> j;
    j--;
    if (i == 0) {
      last = p[j].first < p[j].second ? p[j].first : p[j].second;
    } else {
      string lo = p[j].first < p[j].second ? p[j].first : p[j].second;
      string hi = lo == p[j].first ? p[j].second : p[j].first;
      if (lo >= last)
        last = lo;
      else if (hi >= last)
        last = hi;
      else
        ok = false;
    }
  }
  puts(ok ? "YES" : "NO");
  return 0;
}
