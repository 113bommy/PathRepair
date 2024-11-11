#include <bits/stdc++.h>
using namespace std;
long long n, a, o, t, i;
string s1, s2, s3;
set<string> s;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s1 >> s2;
    s3 = s1 + '-' + s2;
    s.insert(s3);
  }
  cout << s.size();
  return 0;
}
