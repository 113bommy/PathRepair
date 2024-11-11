#include <bits/stdc++.h>
using namespace std;
const int INF = 2123456789;
int a, b, c;
int n, m, k;
int x, y;
string s1;
string s2;
int main() {
  cin >> s1 >> s2;
  int basee = 0;
  for (int i = 0; i < s1.size(); i++) basee = max(basee, s1[i] - '0');
  for (int i = 0; i < s2.size(); i++) basee = max(basee, s2[i] - '0');
  basee += 1;
  int sum = 0;
  int sum2 = 0;
  for (int i = 0; i < s1.size(); i++) {
    sum *= basee;
    sum += s1[i] - '0';
  }
  for (int i = 0; i < s2.size(); i++) {
    sum2 *= basee;
    sum2 += s2[i] - '0';
  }
  sum += sum2;
  int ans = 0;
  while (sum != 0) {
    sum /= basee;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
