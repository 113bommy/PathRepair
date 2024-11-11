#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
int t, n, a, b, cnt1, cnt2;
string s;
int main() {
  cin >> n;
  cin >> s;
  cnt1 = n / 11;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '8') cnt2++;
  }
  cout << min(cnt1, cnt2) << endl;
  return 0;
}
