#include <bits/stdc++.h>
using namespace std;
int A[1 << 10][1 << 10];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  auto c = *min_element(s.begin(), s.end());
  int mi = 1e9;
  for (int i = 0; i < s.size(); ++i) {
    if (mi > s[i] or s[i] == c)
      cout << "Mike\n";
    else
      cout << "Ann\n";
    mi = min(mi, (int)s[i]);
  }
}
