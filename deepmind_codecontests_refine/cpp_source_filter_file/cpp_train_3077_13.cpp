#include <bits/stdc++.h>
using namespace std;
bool b;
long long N, M, ans;
const int C = (1 << 30);
string s;
int main(void) {
  long long i, j, k, l;
  cin >> N;
  i = 0;
  getline(cin, s);
  getline(cin, s);
  j = N - 1;
  if (j > s.size() - 1) j = s.size() - 1;
  for (l = j; l < s.size(); l--) {
    if (i == l) {
      cout << "Impossible" << endl;
      return 0;
    }
    if (s[l] == '!' || s[l] == '?' || s[l] == '.') {
      ans++;
      i = l + 1;
      l = i + N;
      if (l > s.size()) l = s.size();
    }
    if (i >= s.size() - 1) break;
  }
  cout << ans << endl;
  return 0;
}
