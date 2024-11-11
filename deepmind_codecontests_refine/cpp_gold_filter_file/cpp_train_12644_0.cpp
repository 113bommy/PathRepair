#include <bits/stdc++.h>
using namespace std;
const int N = 111111;
const int INF = 1000000000, mod = 1000000007;
const long long LLINF = 1000000000000000000ll;
pair<string, string> a[N];
int p[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  string mx = "";
  for (int j = 0; j < n; ++j) {
    int i = p[j];
    if (j == 0) {
      mx = min(a[i].first, a[i].second);
      continue;
    }
    if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    if (a[i].first < mx) {
      if (a[i].second < mx) {
        puts("NO");
        return 0;
      }
      mx = a[i].second;
    } else
      mx = a[i].first;
  }
  puts("YES");
  return 0;
}
