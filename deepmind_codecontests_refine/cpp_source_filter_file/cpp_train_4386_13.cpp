#include <bits/stdc++.h>
using namespace std;
const long long MAXLL = 9223372036854775807;
const int MAXINT = 2147483647;
const int MAX = 300000;
long long n;
string s;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> s;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] >= s[i + 1]) {
      s.erase(i, 1);
      break;
    }
  }
  if (s.size() == n) s.erase(n - 1, 1);
  cout << s << '\n';
  return 0;
}
