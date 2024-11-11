#include <bits/stdc++.h>
using namespace std;
int solve() {
  string s;
  cin >> s;
  long long neg = (s[0] == '-');
  string r = "";
  auto it = find(s.begin(), s.end(), '.');
  long long idx = it - s.begin();
  long long cnt = 0;
  for (long long i = idx - 1; i >= 0; i--) {
    r += s[i];
    cnt++;
    if (cnt == 3 && i != neg) r += ',', cnt = 0;
  }
  reverse(r.begin(), r.end());
  if (r[0] == '-') r.erase(r.begin());
  cnt = 0;
  idx = it - s.begin();
  idx++;
  r += '.';
  while (idx < (long long int)s.size() && cnt < 2) {
    r += s[idx];
    idx++;
    cnt++;
  }
  while (cnt < 2) r += '0', cnt++;
  r = '$' + r;
  if (neg) r = '(' + r, r += ')';
  cout << r << "\n";
  return 0;
}
int main() {
  auto start = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test_cases = 1;
  while (test_cases--) solve();
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
}
