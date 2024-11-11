#include <bits/stdc++.h>
using namespace std;
time_t start = clock();
typedef long long lld;
typedef double lf;
typedef vector<int> vi;
int mn = -2000000000, mx = 2000000000;
int n, x;
string s;
char c;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> x >> c;
    if (s == ">=" && c == 'Y') mn = max(mn, x);
    if (s == ">" && c == 'Y') mn = max(mn, x + 1);
    if (s == ">=" && c == 'N') mx = min(mx, x - 1);
    if (s == ">" && c == 'N') mx = min(mx, x);
    if (s == "<=" && c == 'Y') mx = min(mx, x);
    if (s == "<" && c == 'Y') mx = min(mx, x - 1);
    if (s == "<=" && c == 'N') mn = max(mn, x + 1);
    if (s == "<" && c == 'N') mn = min(mx, x);
  }
  if (mn <= mx)
    cout << mn;
  else
    cout << "Impossible";
  return 0;
}
